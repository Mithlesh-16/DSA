#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

//   Definition for a binary tree node.
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
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        //TreeNode for root, and int for horizontal index
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        queue <pair<TreeNode *, int>> q;
        map <int, vector<int>> mp;
        q.push(make_pair(root, 0));

        while(!q.empty()){
                pair <TreeNode *, int> tmp = q.front();
                q.pop();
                int hd = tmp.second, data = tmp.first -> val;
                mp[hd].push_back(data);

                if(tmp.first -> left)
                    q.push(make_pair(tmp.first -> left, hd - 1));
                
                if(tmp.first -> right)
                    q.push(make_pair(tmp.first -> right, hd + 1));
                
        }        
        
        for(auto i: mp){
            ans.push_back(i.second);
        }

        return ans;
    }
};



//vertical order Traversal with level and horizontal index tracking 
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
    //Hd stands for Horizontal Distance from root
    vector<vector<int>> verticalOrder(Node *root) {
        //TreeNode for root, and int for horizontal index
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        queue <pair<int, pair<int, Node*>>> q;
        map <int, map<int, vector<int>>> mp;
        q.push(make_pair(0, make_pair(0, root)));

        while(!q.empty()){
            pair<int, pair<int, Node*>> tmp = q.front();
            q.pop();
            
            int hd = tmp.first;
            int lvl = tmp.second.first;
            Node* val = tmp.second.second;
            
            mp[hd][lvl].push_back(val -> data);
            
            if(val -> left) 
                q.push(make_pair(hd - 1, make_pair(lvl+1, val -> left)));
            
            if(val -> right)
                q.push(make_pair(hd + 1, make_pair(lvl + 1, val -> right)));
            
        }        
        
        for( auto i: mp){
            vector<int> tmp;
            for( auto j : i.second){
                for( auto k : j.second){
                    tmp.push_back(k);
                }
            }
            ans.push_back(tmp);
        }

        return ans;
    }
};

