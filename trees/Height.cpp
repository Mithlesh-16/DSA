#include <iostream>
#include <algorithm>

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
    void Max_depth(TreeNode *root, int cnt, int &max_cnt){
        if(root -> left == NULL && root -> right == NULL){
            max_cnt = max(max_cnt, cnt);
            return ;
        }

        if(root -> left) Max_depth(root -> left, cnt + 1, max_cnt);

        if(root -> right) Max_depth(root -> right, cnt + 1, max_cnt);
    }
public:
    int maxDepth(TreeNode* root) {
        
        int max_cnt = 0;
        
        if(root)
            Max_depth(root, 1, max_cnt);

        return max_cnt;
    }
};


class Solution{
    public: 
        int height(TreeNode* root){
            if(root == NULL) return 0;
            int left = height(root -> left);
            int right = height(root -> right);

            return max(left, right) + 1;
        }
};
int main() {

    

return 0;
}