#include <iostream>
using namespace std;

//do insertion , Searching and deletion of any node in BST
// smaller value goes to left;
// larger value goes to right;


class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this -> data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution{
    public:
    
    Node* insertion(Node* root, int val){
        if(root == NULL){
            Node* tmp = new Node(val);
            return tmp;
        }

        

        if(val < root -> data){
            root -> left = insertion(root -> left, val);
        }
        else{
            root -> right = insertion(root -> right, val);
        }

        return root;
    }

    Node* search(Node* root, int val){
        if(root == NULL){
            return NULL;
        }

        if(val == root -> data){
            return root;
        }
        else if( val < root -> data){
            return search(root -> left, val);
        }
        else{
            return search(root -> right, val);
        }
    }


    //more preferred solution 
    Node* deletion(Node* root, int val){
        if(root == NULL){
            return NULL;
        }

        if(root -> data < val){
            root -> left = deletion(root -> left, val);
        }
        else if(root -> data > val){
            root -> right = deletion(root -> right, val);
        }
        else{

            //0 child
            if(root -> data == val && !root -> left && !root -> right){
                root = NULL;
                return root;
            }

            //1 child
            if(root -> data == val && !root -> left && root -> right){
                Node* tmp = root -> right;
                root = NULL;
                return tmp;
            }

            if(root -> data == val && root -> left && !root -> right){
                Node* tmp = root -> left;
                root = NULL;
                return tmp;
            }

            //2 Child

            if(root -> data == val && root -> left && root -> right){

                //find Inorder Successor
                Node* prev = root;
                Node* curr = curr -> right;

                while(curr -> left){
                    prev = curr;
                    curr = curr -> left;
                }

                if(prev -> right == curr){
                    prev -> right = curr -> right;
                }
                else{
                    prev -> left = curr -> right;
                }
            }      
        }

        return root;
    }


    Node* deleteNode(Node* root, int key) {
        if(root == NULL){
            return root;
        }
        if(key < root -> data){
            root -> left = deleteNode(root -> left, key);
        }
        else if(key > root ->data){
            root -> right = deleteNode(root -> right, key);
        }
        else if(key == root -> data){
            // 0 Child
            if(!root -> left && !root -> right){
                return root;
            }
            
            // 1 child
            if(!root -> right){
                Node* tmp = root -> left;
                return tmp;
            }

            if(!root -> left){
                Node* tmp = root -> right;
                return tmp;
            }

                // 2 child
                //find inorder successor
                Node* curr = root -> right;
                while(curr -> left){
                    curr = curr -> left;
                    
                }
                root -> data = curr -> data;
                root -> right = deleteNode(root -> right, curr -> data);
        }

        return root;
    }
    

};

