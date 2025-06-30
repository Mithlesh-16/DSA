#include <iostream>
using namespace std;

//Linked List Class
class ListNode{
    public:
        int val;
        ListNode* next;

        //constructors
        ListNode():val(0), next(nullptr){};
        ListNode(int val):val(val), next(nullptr){};
        ListNode(int val, ListNode* next):val(val),next(next){};
        
        //destructor
        ~ListNode(){
            cout<<"deleted node having value : "<<this -> val<<endl;
        }
};

//Done through the iterative method
ListNode* reverse_LL(ListNode* &head){
    ListNode* curr = head;
    ListNode* prev = nullptr;
    
    while(curr != nullptr){
        ListNode* next_node = curr -> next;     //store next of current node
        curr -> next = prev;    //pointing next of curr to prev
        prev = curr;        //updating prev
        curr = next_node;        //updating curr
    }
    return prev;
}

//Done through the Recursive Method
ListNode* reverse_LL_recurisvely(ListNode* head){

    return head;
}

int main() {

    ListNode* L1 = new ListNode(10);

    

    return 0;
}