#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

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

class Solution{
    public:
        vector<int> bottomView(Node *root) {
        
        vector<int> ans;
        queue<pair<int, Node*>> q;
        map <int, int> mp;
        q.push(make_pair(0, root));
        
        while(!q.empty()){
            pair<int, Node*> tmp = q.front();
            q.pop();
            
            int hd = tmp.first;
            Node* tmp_Node = tmp.second;
            
            mp[hd] = tmp_Node -> data;
            
            if(tmp_Node -> left)
                q.push(make_pair(hd -1, tmp_Node -> left));
            if(tmp_Node -> right)
                q.push(make_pair(hd + 1, tmp_Node -> right));
        }
        
        for(auto i : mp){
            ans.push_back(i.second);
        }
        
        return ans;
    }
};


class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        
        queue <pair<int, Node*>> q;
        map <int, int> mp;
        vector<int> ans;
        
        q.push(make_pair(0, root));
        while(!q.empty()){
            pair<int, Node*> tmp = q.front();
            q.pop();
            
            int hd = tmp.first;
            Node* tmp_Node = tmp.second;
            
            if(mp.find(hd) == mp.end()) 
                mp[hd] = tmp_Node -> data;
            
            if(tmp_Node -> left)
                q.push(make_pair(hd -1, tmp_Node -> left));
            if(tmp_Node -> right)
                q.push(make_pair(hd + 1, tmp_Node -> right));
            
        }
        
        for(auto i : mp){
            ans.push_back(i.second);
        }
        
        return ans;
    }
};