#include <iostream>
using namespace std;

class TreeNode{
    public:
        TreeNode* left;
        TreeNode* right;
        int data;
    
    TreeNode(int data){
        this -> data = data;
        left = NULL;
        right = NULL;
    }

};

class solution{
    public:
        pair<bool, int> balanced(TreeNode* root){
            if(root == NULL){
                pair<bool, int> p = make_pair(true, 0);
                return p;
            }
            
            pair<bool, int> left = balanced(root -> left);
            pair<bool, int> right = balanced(root -> right);

            pair<bool, int> ans;
            ans.second = max(left.second, right.second) + 1;

            if(left.first && right.first)
                ans.first = abs(left.second - right.second) <= 1;
            else ans.first = false;

            return ans;
        }
    
        bool isBalanced(TreeNode* root){
            return balanced(root).first;
        }
};

int main() {


return 0;
}