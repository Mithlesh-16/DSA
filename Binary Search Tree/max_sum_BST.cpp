// Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.


// Example 1:
// Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
// Output: 20
// Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.

// Example 2:
// Input: root = [4,3,null,1,2]
// Output: 2
// Explanation: Maximum sum in a valid Binary search tree is obtained in a single root node with key equal to 2.

// Example 3:
// Input: root = [-4,-2,-5]
// Output: 0
// Explanation: All values are negatives. Return an empty BST.


#include<bits/stdc++.h>
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

class info {
public:
    int maxi;
    int mini;
    int sum = 0;
    bool isBST;
};
class Solution {
    info solve(TreeNode* root, int &max_sum) {
        if (root == NULL) {
            info ans;
            ans.maxi = INT_MIN;
            ans.mini = INT_MAX;
            ans.sum = 0;
            ans.isBST = true;
            return ans;
        }
        
        //post Traversal
        info leftInfo = solve(root->left, max_sum);
        info rightInfo = solve(root->right, max_sum);

        info ans;

        ans.mini = min(leftInfo.mini, root->val);
        ans.maxi = max(rightInfo.maxi, root->val);
        ans.sum = leftInfo.sum + rightInfo.sum + root -> val;

        if (leftInfo.isBST and rightInfo.isBST and
            (rightInfo.mini > root->val and leftInfo.maxi < root->val)) {
            ans.isBST = true;
        } else {
            ans.isBST = false;
            ans.sum = 0;
        }
        max_sum = max(max_sum, ans.sum);

        return ans;
    }

public:
    int maxSumBST(TreeNode* root) {
        info ans;
        int max_sum = 0;
        ans = solve(root, max_sum);
        return max_sum;
    }
};