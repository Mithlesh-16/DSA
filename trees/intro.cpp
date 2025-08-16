#include <iostream>
#include <queue>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *build_tree(node *root)
{
    int data = 0;
    cout << "Enter data : " << endl;
    cin >> data;

    root = new node(data);

    // base case
    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for the left of node  " << data << " : " << endl;

    root->left = build_tree(root->left);

    cout << "Enter data for the right of node  " << data << " : " << endl;

    root->right = build_tree(root->right);

    return root;
}

// level order traversal
void level_order_traversal(node *root)
{

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL) // purana level traverse ho chuka hai
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }
}

//reverse level order tarversal
void reverse_level_order_traversal(node *root){
    
}


int main()
{

    node *root = NULL;
    // 1 3 7 -1 -1 9 -1 -1 5 -1 -1
    root = build_tree(root);

    cout << "level order traversal : " << endl;
    level_order_traversal(root);

    return 0;
}