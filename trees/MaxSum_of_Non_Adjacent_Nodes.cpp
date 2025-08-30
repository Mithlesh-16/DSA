#include <iostream>
using namespace std;
#include <algorithm>

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
    // pair ->  first = sum with elements included in current level
    // pair -> second = sum with elements excluded in current level
    pair<int, int> solve(Node* root){
        //base case
        if(root == NULL){
            pair<int, int> p = make_pair(0,0);
            return p;
        }
        
        pair<int, int> leftAns = solve(root -> left);
        pair<int, int> rightAns = solve(root -> right);
        
        pair<int, int> ans;
        ans.first = leftAns.second + rightAns.second + root -> data;
        ans.second = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);
        
        return ans;
    }
  public:
    int getMaxSum(Node *root) {
        
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
        
    }
};