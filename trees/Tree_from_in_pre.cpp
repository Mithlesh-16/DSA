#include <iostream>
#include <map>
#include <vector>
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
    
    TreeNode* solve(vector<int> &preorder, vector<int> &inorder, int &preorder_start, int inorder_start, int inorder_end, map<int, int> &mp){
        //base case
        if((preorder_start >= preorder.size()) || (inorder_start > inorder_end)){
            return NULL;
        }

        int element = preorder[preorder_start++];
        TreeNode* root = new TreeNode(element);
        int index = mp[element];
        root -> left = solve(preorder, inorder, preorder_start, inorder_start, index -1, mp);
        root -> right = solve(preorder, inorder, preorder_start, index + 1, inorder_end, mp);
        
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorder_start = 0;
        map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        return solve(preorder, inorder, preorder_start, 0, inorder.size() - 1, mp);
    }
};