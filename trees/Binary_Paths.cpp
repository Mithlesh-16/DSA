#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
    
        TreeNode(int val){
            this -> val = val;
            right = left = NULL;
        }
};

void BreadthFirstSearch(vector<string> &ans, string tmp, TreeNode* root){
    tmp += to_string(root -> val);
    tmp += "->";
    if(root -> left == NULL && root -> right == NULL){
        tmp = tmp.substr(0, tmp.size() - 2);
        ans.push_back(tmp);
    }

    if(root -> left)    BreadthFirstSearch(ans, tmp, root);
    if(root -> right)   BreadthFirstSearch(ans, tmp, root);
}

vector<string> BinaryPaths(TreeNode* root){
    string tmp = "";
    vector<string> ans;
    BreadthFirstSearch(ans, tmp, root);

    return ans;
}

int main() {


return 0;
}