#include <iostream>
using namespace std;

// H.W. question to reverse doubly linked list

//Linked List Class
class ListNode{
    public:
        int val;
        ListNode* next;
        ListNode* prev;

        //constructors
        ListNode():val(0), next(nullptr), prev(nullptr){};
        ListNode(int val):val(val), next(nullptr), prev(nullptr){};
        ListNode(int val, ListNode* next) : val(val), next(next), prev(nullptr){};
        ListNode(int val, ListNode* prev) : val(val), next(nullptr), prev(prev){};
        ListNode(int val, ListNode* next, ListNode* prev):val(val),next(next), prev(prev){};
        
        //destructor
        ~ListNode(){
            cout<<"deleted node having value : "<<this -> val<<endl;
        }

};

//reversing doubly LL 
class Solution{
    public:
    ListNode* reverse_doubly_LL(ListNode* head){
        ListNode* curr = nullptr;
        while(head != nullptr){
            curr = head;
            ListNode* temp = head -> next;
            head -> next = head -> prev;
            head -> prev = temp;
            head = temp;
        }
        return curr;
    }
};

int main() {


return 0;
}