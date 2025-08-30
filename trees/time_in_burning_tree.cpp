// Q - 2385. Amount of Time for Binary Tree to Be Infected
// You are given the root of a binary tree with unique values, && an integer start. At minute 0, an infection starts from the node with value start.

// Each minute, a node becomes infected if:

// The node is currently uninfected.
// The node is adjacent to an infected node.
// Return the number of minutes needed for the entire tree to be infected.

 

// Example 1:


// Input: root = [1,5,3,null,4,10,6,9,2], start = 3
// Output: 4
// Explanation: The following nodes are infected during:
// - Minute 0: Node 3
// - Minute 1: Nodes 1, 10 && 6
// - Minute 2: Node 5
// - Minute 3: Node 4
// - Minute 4: Nodes 9 && 2
// It takes 4 minutes for the whole tree to be infected so we return 4.









#include <iostream>
using namespace std;
#include <map>
#include <queue>

// Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};

class Solution {

    int burnTree(map<TreeNode* , TreeNode*> &nodeToParent, TreeNode* target){
        queue<TreeNode*> q;
        map <TreeNode*, bool> visited;

        q.push(target);
        visited[target] = true;
        int time = 0;
        
        while(!q.empty()){
            int size = q.size();
            bool flag = false;
            for(int i = 0; i < size; i++){
                TreeNode* tmp = q.front();
                q.pop();
                visited[tmp] = true;

                if(tmp -> left && !visited[tmp -> left]){
                    flag = true;
                    q.push(tmp -> left);
                    visited[tmp -> left] = true;
                }

                if(tmp -> right && !visited[tmp -> right]){
                    flag = true;
                    q.push(tmp -> right);
                    visited[tmp -> right] = true;
                }

                TreeNode* parent = nodeToParent[tmp];
                if(parent && !visited[parent]){
                    flag = true;
                    q.push(parent);
                    visited[parent] = true;
                }

                
            }
            if(flag) time++;

        }

        return time;
    }

    TreeNode* make_map(map<TreeNode*, TreeNode*> &nodeToParent, TreeNode* root, int target) {
        queue<TreeNode*> q;
        q.push(root);
        nodeToParent[root] = NULL;
        TreeNode* res = NULL;

        while (!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            if(tmp -> val == target){
                res = tmp;
            }

            if (tmp->left) {
                q.push(tmp->left);
                nodeToParent[tmp->left] = tmp;
            }
            if (tmp->right) {
                q.push(tmp->right);
                nodeToParent[tmp->right] = tmp;
            }
        }
        return res;
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        
        map<TreeNode*, TreeNode*> nodeToParent;
        TreeNode* target = make_map(nodeToParent, root, start);

        return burnTree(nodeToParent, target);
    }
};