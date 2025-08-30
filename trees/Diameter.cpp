#include <iostream>
#include <bits/stdc++.h>
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

class Soln{
    
    public:

        pair<int, int> fastDiameter(TreeNode* root){
            if(!root){
                pair<int, int> p = make_pair(0,0);
                return p;
            }

            pair<int, int> left = fastDiameter(root -> left);
            pair<int, int> right = fastDiameter(root -> right);

            int op1 = left.first;
            int op2 = right.first;
            int op3 = left.second + right.second + 1;

            //  pair.first = diameter;
            //  pair.second = height;

            pair<int, int> ans;
            ans.first = max(max(op1, op2), op3);
            ans.second = max(left.second, right.second) + 1;

            return ans;
        }

        int diameter(TreeNode* root){

            return fastDiameter(root).first;
        }
};

int main() {


return 0;
}