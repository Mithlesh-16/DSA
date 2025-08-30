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
    

    TreeNode* solve(vector<int> &postorder, vector<int> &inorder, int &postorder_start, int inorder_start, int inorder_end, map<int, int> &mp){
        //base case
        if((postorder_start < 0) || (inorder_start > inorder_end)){
            return NULL;
        }

        int element = postorder[postorder_start--];
        TreeNode* root = new TreeNode(element);
        int index = mp[element];
        
        //in case of postorder : we will built the right part of tree first as the next element comes in right subTree;
        root -> right = solve(postorder, inorder, postorder_start, index + 1, inorder_end, mp);
        root -> left = solve(postorder, inorder, postorder_start, inorder_start, index -1, mp);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder) {
        int postorder_start = inorder.size() - 1;
        map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        return solve(postorder, inorder, postorder_start, 0, inorder.size() - 1, mp);
    }
};

