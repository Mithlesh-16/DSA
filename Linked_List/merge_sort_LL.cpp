#include <iostream>
using namespace std;

class ListNode{

    public:
        int val;
        ListNode* next;

        //Constructors 
        ListNode() : val(0), next(nullptr){};
        ListNode(int val) : val(val), next(nullptr){};
        ListNode(int val, ListNode* next) : val(val), next(next){};
        
        //Destructors
        ~ListNode(){
            cout<<"Linked List Destructed here at Node with value : "<<this -> val<<endl;
        }

};

/**
 * Definition for singly-linked list.
 * 
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head -> next;

        while(fast and fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right){
        if(left == NULL) return right;
        if(right == NULL) return left;

        if(left -> val < right -> val){
            left -> next =  merge(left -> next, right);
            return left;
        }else{
            right -> next = merge(left, right -> next);
            return right;
        }
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }

        //find Middle
        ListNode* mid = findMiddle(head);

        ListNode* right = mid -> next;
        ListNode* left = head;
        mid -> next = NULL;         //seperate both parts of the LL

        left = sortList(left);
        right = sortList(right);

        //merge 
        return merge(left, right);
    }
};



int main()
{

    return 0;
}