#include <iostream>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int solve(TreeNode* root, int &i, int k){
        if(!root){
            return -1;
        }

        int leftAns = solve(root -> left, i, k);
        i++;
        if(i == k) return root -> val;
        int rightAns = solve(root -> right, i, k);

        return max(leftAns, rightAns);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        return solve(root, i, k);
    }
};