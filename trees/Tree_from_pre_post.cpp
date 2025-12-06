#include <bits/stdc++.h>
using namespace std;

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
    int preIndex = 0;

    TreeNode* build(vector<int>& pre, vector<int>& post, 
                    int postStart, int postEnd, int n) {
        
        if (preIndex >= n || postStart > postEnd) 
            return NULL;

        TreeNode* root = new TreeNode(pre[preIndex++]);

        // Leaf node
        if (postStart == postEnd) 
            return root;

        // Next element in preorder is left child
        int leftChild = pre[preIndex];

        // Find it in postorder (left subtree end)
        int i;
        for (i = postStart; i <= postEnd; i++) {
            if (post[i] == leftChild)
                break;
        }

        // Build subtrees
        root->left = build(pre, post, postStart, i, n);
        root->right = build(pre, post, i + 1, postEnd - 1, n);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        return build(pre, post, 0, n - 1, n);
    }
};
