

// Node is as follows
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution {
    void solve(Node* root, vector<int> &ans){
        if(root == NULL) return ;
        
        solve(root -> left, ans);
        ans.push_back(root -> data);
        solve(root -> right, ans);
    }
  public:
    bool findTarget(Node *root, int target) {
        vector<int> ans;
        solve(root, ans);
        
        int i = 0, j = ans.size() - 1;
        while(i < j){
            if(ans[i] + ans[j] < target) i++;
            else if(ans[i] + ans[j] > target) j--;
            else return true;
        }
        
        return false;
    }
};