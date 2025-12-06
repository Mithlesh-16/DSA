#include <iostream>
using namespace std;

// A BTree node
class BTreeNode {
    int *keys;      // An array of keys
    int t;          // Minimum degree (defines the range for number of keys)
    BTreeNode **C;  // An array of child pointers
    int n;          // Current number of keys
    bool leaf;      // Is true when node is leaf. Otherwise false

public:
    BTreeNode(int _t, bool _leaf);

    // Helper functions
    void traverse();
    int findKey(int k);
    
    // Core Operations
    void insertNonFull(int k);
    void splitChild(int i, BTreeNode *y);
    void remove(int k);
    
    // Deletion Helpers
    void removeFromLeaf(int idx);
    void removeFromNonLeaf(int idx);
    int getPred(int idx);
    int getSucc(int idx);
    void fill(int idx);
    void borrowFromPrev(int idx);
    void borrowFromNext(int idx);
    void merge(int idx);

    // Make BTree a friend so it can access private members
    friend class BTree;
};

class BTree {
    BTreeNode *root;
    int t; // Minimum degree

public:
    BTree(int _t) {
        root = NULL;
        t = _t;
    }

    void traverse() {
        if (root != NULL) root->traverse();
    }

    void insert(int k);
    void remove(int k);
};

// Constructor for BTreeNode
BTreeNode::BTreeNode(int t1, bool leaf1) {
    t = t1;
    leaf = leaf1;
    keys = new int[2 * t - 1];
    C = new BTreeNode *[2 * t];
    n = 0;
}

// Traverse the tree
void BTreeNode::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        if (leaf == false)
            C[i]->traverse();
        cout << " " << keys[i];
    }
    if (leaf == false)
        C[i]->traverse();
}

// Find the index of the first key that is greater than or equal to k
int BTreeNode::findKey(int k) {
    int idx = 0;
    while (idx < n && keys[idx] < k)
        ++idx;
    return idx;
}

// --- INSERTION IMPLEMENTATION ---

void BTree::insert(int k) {
    if (root == NULL) {
        root = new BTreeNode(t, true);
        root->keys[0] = k;
        root->n = 1;
    } else {
        if (root->n == 2 * t - 1) {
            // If root is full, tree grows in height
            BTreeNode *s = new BTreeNode(t, false);
            s->C[0] = root;
            s->splitChild(0, root);
            
            // New root has two children now. Decide which one has the new key
            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->C[i]->insertNonFull(k);
            
            root = s;
        } else {
            root->insertNonFull(k);
        }
    }
}

// Insert into a node that is NOT full
void BTreeNode::insertNonFull(int k) {
    int i = n - 1;

    if (leaf == true) {
        // Find location and shift keys to make space
        while (i >= 0 && keys[i] > k) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = k;
        n = n + 1;
    } else {
        // Find the child which is going to have the new key
        while (i >= 0 && keys[i] > k)
            i--;

        // Check if that child is full
        if (C[i + 1]->n == 2 * t - 1) {
            splitChild(i + 1, C[i + 1]);
            
            // After split, the middle key goes up and C[i+1] is split into two.
            // Check which of the two is the new location
            if (keys[i + 1] < k)
                i++;
        }
        C[i + 1]->insertNonFull(k);
    }
}

// Split the child y of this node. i is the index of y in C array
void BTreeNode::splitChild(int i, BTreeNode *y) {
    // Create a new node z which will store (t-1) keys of y
    BTreeNode *z = new BTreeNode(y->t, y->leaf);
    z->n = t - 1;

    // Copy the last (t-1) keys of y to z
    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];

    // Copy the last t children of y to z
    if (y->leaf == false) {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j + t];
    }

    // Reduce the number of keys in y
    y->n = t - 1;

    // Create space for new child in this node
    for (int j = n; j >= i + 1; j--)
        C[j + 1] = C[j];

    // Link the new child
    C[i + 1] = z;

    // Move a key of y to this node
    for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    keys[i] = y->keys[t - 1];
    n = n + 1;
}

// --- DELETION IMPLEMENTATION ---

void BTree::remove(int k) {
    if (!root) {
        cout << "The tree is empty\n";
        return;
    }

    root->remove(k);

    // If the root node has 0 keys, make its first child the new root
    // (unless it is a leaf, in which case the tree is empty)
    if (root->n == 0) {
        BTreeNode *tmp = root;
        if (root->leaf)
            root = NULL;
        else
            root = root->C[0];
        delete tmp;
    }
}

void BTreeNode::remove(int k) {
    int idx = findKey(k);

    // Case 1 & 2: The key k is present in this node
    if (idx < n && keys[idx] == k) {
        if (leaf)
            removeFromLeaf(idx);
        else
            removeFromNonLeaf(idx);
    }
    else {
        // Case 3: The key is not here. We must go deeper.
        if (leaf) {
            cout << "The key " << k << " does not exist in the tree\n";
            return;
        }

        // Flag if the key is in the last child
        bool flag = ((idx == n) ? true : false);

        // Ensure the child where the key exists has at least t keys
        if (C[idx]->n < t)
            fill(idx);

        // If the last child was merged, it must have merged with the previous child
        // so we recurse on the (idx-1)th child. Else, we recurse on the (idx)th child.
        if (flag && idx > n)
            C[idx - 1]->remove(k);
        else
            C[idx]->remove(k);
    }
}

void BTreeNode::removeFromLeaf(int idx) {
    // Shift all keys after idx backwards
    for (int i = idx + 1; i < n; ++i)
        keys[i - 1] = keys[i];
    n--;
}

void BTreeNode::removeFromNonLeaf(int idx) {
    int k = keys[idx];

    // If the child that precedes k (C[idx]) has at least t keys,
    // find the predecessor 'pred' of k in the subtree rooted at C[idx].
    // Replace k by pred. Recursively delete pred in C[idx].
    if (C[idx]->n >= t) {
        int pred = getPred(idx);
        keys[idx] = pred;
        C[idx]->remove(pred);
    }
    // If C[idx] has < t keys, examine C[idx+1]. If it has >= t keys,
    // find successor 'succ' of k. Replace k by succ. Recursively delete succ.
    else if (C[idx + 1]->n >= t) {
        int succ = getSucc(idx);
        keys[idx] = succ;
        C[idx + 1]->remove(succ);
    }
    // If both C[idx] and C[idx+1] has less than t keys, merge k and all of C[idx+1]
    // into C[idx]. Then C[idx] contains 2t-1 keys. Free C[idx+1] and recursively delete k from C[idx].
    else {
        merge(idx);
        C[idx]->remove(k);
    }
}

int BTreeNode::getPred(int idx) {
    BTreeNode *cur = C[idx];
    while (!cur->leaf)
        cur = cur->C[cur->n];
    return cur->keys[cur->n - 1];
}

int BTreeNode::getSucc(int idx) {
    BTreeNode *cur = C[idx + 1];
    while (!cur->leaf)
        cur = cur->C[0];
    return cur->keys[0];
}

// A function to fill child C[idx] which has less than t-1 keys
void BTreeNode::fill(int idx) {
    // If the previous child(C[idx-1]) has more than t-1 keys, borrow a key from that child
    if (idx != 0 && C[idx - 1]->n >= t)
        borrowFromPrev(idx);

    // If the next child(C[idx+1]) has more than t-1 keys, borrow a key from that child
    else if (idx != n && C[idx + 1]->n >= t)
        borrowFromNext(idx);

    // Merge C[idx] with its sibling
    // If C[idx] is the last child, merge it with with its previous sibling
    // Otherwise merge it with its next sibling
    else {
        if (idx != n)
            merge(idx);
        else
            merge(idx - 1);
    }
}

void BTreeNode::borrowFromPrev(int idx) {
    BTreeNode *child = C[idx];
    BTreeNode *sibling = C[idx - 1];

    // Shift child keys and children forward to make space for the new key
    for (int i = child->n - 1; i >= 0; --i)
        child->keys[i + 1] = child->keys[i];

    if (!child->leaf) {
        for (int i = child->n; i >= 0; --i)
            child->C[i + 1] = child->C[i];
    }

    // Set child's first key equal to keys[idx-1] from current node
    child->keys[0] = keys[idx - 1];

    // Move sibling's last child as child's first child
    if (!child->leaf)
        child->C[0] = sibling->C[sibling->n];

    // Move the key from the sibling to the parent
    keys[idx - 1] = sibling->keys[sibling->n - 1];

    child->n += 1;
    sibling->n -= 1;
}

void BTreeNode::borrowFromNext(int idx) {
    BTreeNode *child = C[idx];
    BTreeNode *sibling = C[idx + 1];

    // keys[idx] is inserted as the last key in C[idx]
    child->keys[child->n] = keys[idx];

    // Sibling's first child is inserted as the last child of C[idx]
    if (!(child->leaf))
        child->C[(child->n) + 1] = sibling->C[0];

    // The first key from sibling is inserted into keys[idx]
    keys[idx] = sibling->keys[0];

    // Shift all keys and children in sibling backward
    for (int i = 1; i < sibling->n; ++i)
        sibling->keys[i - 1] = sibling->keys[i];

    if (!sibling->leaf) {
        for (int i = 1; i <= sibling->n; ++i)
            sibling->C[i - 1] = sibling->C[i];
    }

    child->n += 1;
    sibling->n -= 1;
}

void BTreeNode::merge(int idx) {
    BTreeNode *child = C[idx];
    BTreeNode *sibling = C[idx + 1];

    // Pulling a key from the current node and inserting it into (t-1)th position of child
    child->keys[t - 1] = keys[idx];

    // Copying the keys from sibling to child
    for (int i = 0; i < sibling->n; ++i)
        child->keys[i + t] = sibling->keys[i];

    // Copying the child pointers from sibling to child
    if (!child->leaf) {
        for (int i = 0; i <= sibling->n; ++i)
            child->C[i + t] = sibling->C[i];
    }

    // Shift keys and children in the current node to fill the gap created by moving keys[idx]
    for (int i = idx + 1; i < n; ++i)
        keys[i - 1] = keys[i];
    for (int i = idx + 2; i <= n; ++i)
        C[i - 1] = C[i];

    child->n += sibling->n + 1;
    n--;

    delete (sibling);
}

// --- MAIN FUNCTION TO TEST ---
int main() {
    // Create a BTree with min degree 3
    BTree t(3);

    cout << "Inserting 10, 20, 5, 6, 12, 30, 7, 17\n";
    t.insert(10); t.insert(20); t.insert(5); t.insert(6);
    t.insert(12); t.insert(30); t.insert(7); t.insert(17);

    cout << "Traversal of tree: ";
    t.traverse();
    cout << endl;

    cout << "\nDeleting 6 (Leaf node case)...\n";
    t.remove(6);
    cout << "Traversal: "; t.traverse(); cout << endl;

    cout << "\nDeleting 12 (Internal node with valid borrow)...\n";
    t.remove(12);
    cout << "Traversal: "; t.traverse(); cout << endl;

    cout << "\nDeleting 10 (Root/Internal merge case)...\n";
    t.remove(10);
    cout << "Traversal: "; t.traverse(); cout << endl;

    return 0;
}