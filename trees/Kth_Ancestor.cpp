#include<iostream>
using namespace std;


// Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left, *right;
};

// your task is to complete this function
class Solution {
    Node* solve(Node* root, int &k, int node){
        //base case
        if(root == NULL){
            return NULL;
        }
        if(root -> data == node){
            return root;
        }
        
        Node* leftAns = solve(root -> left, k, node);
        Node* rightAns = solve(root -> right, k, node);
        
        
        
        if(leftAns && !rightAns){
                k--;
                if(k >= 0)
                    return root;
                else return leftAns;
        }
        else if(!leftAns && rightAns){
                k--;
                if(k >= 0)
                    return root;
                else return rightAns;
        }
        else return NULL;
        
        
        
    }
  public:
    int kthAncestor(Node *root, int k, int node) {
        // Code here
        Node* ans = solve(root, k, node);
        if(k > 0) return -1;
        return ans -> data;
    }
};
