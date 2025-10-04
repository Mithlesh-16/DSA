#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return root;
        }
        if(key < root -> val){
            root -> left = deleteNode(root -> left, key);
        }
        else if(key > root -> val){
            root -> right = deleteNode(root -> right, key);
        }
        else if(key == root -> val){
            // 0 Child
            if(!root -> left and !root -> right){
                return NULL;
            }
            
            // 1 child
            if(!root -> right){
                TreeNode* tmp = root -> left;
                return tmp;
            }

            if(!root -> left){
                TreeNode* tmp = root -> right;
                return tmp;
            }

                // 2 child
                //find inorder successor
                TreeNode* curr = root -> right;
                TreeNode* prev = root;
                while(curr -> left){
                    prev = curr;
                    curr = curr -> left;
                    
                }
                root -> val = curr -> val;
                
                prev -> right = curr -> right;
        }

        return root;
    }
};