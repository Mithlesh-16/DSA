//morris Traversal
//for PreOrder Traversal

#include <iostream>
#include <vector>
using namespace std;

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution{
    void solve(Node* root, vector<int> ans){
        
        while(root){
            if(!root -> left){
                ans.push_back(root -> data);
                root = root -> right;
            }
            else{
                //find inorder predecessor
                
                Node* curr = root -> left;
                while(curr -> right && curr -> right != root)
                    curr = curr -> right;

                if(curr -> right == NULL){
                    ans.push_back(root -> data);
                    curr -> right = root;
                    root = root -> left;
                }
                else{
                    curr -> right = NULL;
                    root = root -> right;

                }
            }
        }
    }
};

