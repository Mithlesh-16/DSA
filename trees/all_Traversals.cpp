#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// node class
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// building tree
node *build_tree(node *root)
{
    int data = 0;
    cout << "Enter data : " << endl;
    cin >> data;

    // base case
    if (data == -1)
    {
        return NULL;
    }

    root = new node(data);

    cout << "Enter data for left of : " << data << endl;
    root->left = build_tree(root->left);

    cout << "Enter data for right of : " << data << endl;
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
        if (q.front() == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            node *tmp = q.front();
            cout << tmp->data << " ";
            q.pop();
            if (tmp->left)
                q.push(tmp->left);
            if (tmp->right)
                q.push(tmp->right);
        }
    }
}

// Reverse Level Order Traversal
// 
void reverse_level_order_traversal(node *root){
    queue <node *> q;
    stack <node *> s;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node *tmp = q.front();
        s.push(tmp);
        q.pop();
        if(tmp == NULL){
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            if(tmp -> right){
                q.push(tmp -> right);
            }
            if(tmp -> left){
                q.push(tmp -> left);
            }

            
        }
    }

    cout<<"Reverse Level order Traversal : ";
    while(!s.empty()){
        if(s.top()){
            cout<<s.top() -> data<<" ";
        }
        else{
            cout<<endl;
        }
        s.pop();
    }


}

// inorder traversal
//  L N R
void inorder_traversal(node *root)
{
    //base case 
    if(!root) return;
    

    inorder_traversal(root->left);

    cout << root->data << " ";

    inorder_traversal(root->right);
}

// Pre - Order Traversal
// N L R
void preorder_traversal(node *root)
{
    if(!root){
        return ;
    }

    cout<< root -> data << " ";
    preorder_traversal(root -> left);
    preorder_traversal(root -> right);
    
}

// POST - ORDER TRAVERSAL
// L R N
void postOrderTraversal(node *root){
    if(!root){
        return;
    }
    
    postOrderTraversal(root -> left);
    postOrderTraversal(root -> right);
    cout<<root -> data<< " ";
}

node *buildTreeByLevelOrder(node *root){
    queue<node *> q;
    int data = 0;
    cout<<"Enter data for root : "<<endl;
    cin>> data;

    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node *tmp = q.front();
        q.pop();

        
        int data2 = 0;
        cout<<"Enter data for left of "<<tmp -> data<<endl;
        cin>> data2;

        if(data2 != -1){
            tmp -> left = new node(data2);
            q.push(tmp -> left);
        }
        
        
        cout<<"Enter data for right of "<<tmp -> data<<endl;
        cin>> data2;

        if(data2 != -1){
            tmp -> right = new node(data2);
            q.push(tmp -> right);
        }
        
    }

    return root;
}

int main()
{

    node *root = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = build_tree(root);

    cout << "level Order Traversal : " << endl;
    level_order_traversal(root);
    cout<<endl;

    cout << "InOrder Traversal : " << endl;
    inorder_traversal(root);
    cout<<endl;

    cout<<"Pre - Order Traversal : "<<endl;
    preorder_traversal(root);
    cout<<endl;

    cout<<"Post - Order Traversal : "<<endl;
    postOrderTraversal(root);
    cout<<endl;

    cout<<"building Once Again : "<<endl;
    root = buildTreeByLevelOrder(root);

    cout << "level Order Traversal : " << endl;
    level_order_traversal(root);
    cout<<endl;

    cout << "InOrder Traversal : " << endl;
    inorder_traversal(root);
    cout<<endl;

    cout<<"Pre - Order Traversal : "<<endl;
    preorder_traversal(root);
    cout<<endl;

    cout<<"Post - Order Traversal : "<<endl;
    postOrderTraversal(root);
    cout<<endl;

    reverse_level_order_traversal(root);
    cout<<endl;

    return 0;
}