// Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.

// If the tree has more than one mode, return them in any order.

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than or equal to the node's key.
// The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
// Both the left and right subtrees must also be binary search trees.
 

// Example 1:

// Input: root = [1,null,2,2]
// Output: [2]

// Example 2:

// Input: root = [0]
// Output: [0]
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -105 <= Node.val <= 105
 

// Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).




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

class Solution {
    void solve(TreeNode* root, map<int, int> &mp){
        if(root == NULL){
            return ;
        }

        solve(root -> left, mp);
        mp[root -> val]++;
        solve(root -> right, mp);
    }
    
public:
    vector<int> findMode(TreeNode* root) {
        
        map<int, int> mp;
        solve(root, mp);

        vector<int> ans;
        int mode = 0;
        
        for(auto it: mp){
            mode = max(mode, it.second);
        }

        for(auto it: mp){
            if(it.second == mode)
                ans.push_back(it.first);
        }

        return ans;
    }
};