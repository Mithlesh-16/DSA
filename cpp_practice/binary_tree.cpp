#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int val){
        data = val;
        left = right = NULL;
    }
};

node* buildTree(node* root){
    int val;
    cout << "Enter Node Value (-1 for NULL): ";
    cin >> val;

    if(val == -1) return NULL;

    root = new node(val);

    cout << "Enter left child of " << val << endl;
    root->left = buildTree(root->left);

    cout << "Enter right child of " << val << endl;
    root->right = buildTree(root->right);

    return root;
}

// ---------------- Traversals ----------------

void preorderTraversal(node* tmp){
    if(!tmp) return;
    cout << tmp->data << " ";
    preorderTraversal(tmp->left);
    preorderTraversal(tmp->right);
}

void inorderTraversal(node* tmp){
    if(!tmp) return;
    inorderTraversal(tmp->left);
    cout << tmp->data << " ";
    inorderTraversal(tmp->right);
}

void postorderTraversal(node* tmp){
    if(!tmp) return;
    postorderTraversal(tmp->left);
    postorderTraversal(tmp->right);
    cout << tmp->data << " ";
}

void nonRecursiveTraversal(node* root){
    if(!root){
        cout << "Tree Empty!" << endl;
        return;
    }

    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}


// ---------------- BST ----------------

node* insertBST(node* root, int val){
    if(root == NULL) return new node(val);

    if(val < root->data) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);

    return root;
}


// ---------------- Main ----------------

int main(){
    node* root = NULL;
    node* bst = NULL;
    while(true){
        cout << "\n========== MENU ==========\n";
        cout << "1. Build Binary Tree\n";
        cout << "2. Display Tree (Recursive Traversals)\n";
        cout << "3. Display Level Order (BFS)\n";
        cout << "4. Insert in BST\n";
        cout << "5. Display BST Traversals\n";
        cout << "6. Exit\n";
        cout << "Enter Choice: ";
        int choice;
        cin >> choice;
        switch(choice){
            case 1:
                cout << "\n--- Building Binary Tree ---\n";
                root = buildTree(root);
                cout << "Binary Tree Created Successfully.\n";
                break;
            case 2:
                if(!root){
                    cout << "Tree is empty! Build first.\n";
                    break;}
                cout << "\nPreorder: ";
                preorderTraversal(root);
                cout << "\nInorder: ";
                inorderTraversal(root);
                cout << "\nPostorder: ";
                postorderTraversal(root);
                cout << endl;
                break;
            case 3:
                cout << "\nLevel Order: ";
                nonRecursiveTraversal(root);
                cout << endl;
                break;
            case 4: {
                cout << "Enter value to insert in BST (-1 to stop): ";
                while(true){
                    int x;
                    cin >> x;
                    if(x == -1) break;
                    bst = insertBST(bst, x);
                    cout << "Inserted " << x << endl;}
                break;}
            case 5:
                if(!bst){
                    cout << "BST empty! Insert values first.\n";
                    break;}
                cout << "\nBST Inorder: ";
                inorderTraversal(bst);
                cout << "\nBST Preorder: ";
                preorderTraversal(bst);
                cout << "\nBST Postorder: ";
                postorderTraversal(bst);
                cout << "\nBST Level Order: ";
                nonRecursiveTraversal(bst);
                cout << endl;
                break;
            case 6:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid Choice! Try again.\n";
        }}}
