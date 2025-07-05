#include <iostream>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr){};
    ListNode(int val) : val(val), next(nullptr){};
    ListNode(int val, ListNode* next) : val(val), next(next){};

    ~ListNode(){};

};

class Solution{
    public:
    ListNode* middle_of_LL(ListNode* head){
        //  in order to get the soln in only 1 iteration
        //  we can think of it as two players
        //  1. noob (moves 1 node forward at a time)
        //  2. pro  (moves 2 nodes forward at a time)
        //  i.e. two pointers approach

        if(head == nullptr) return head;
        if(head -> next = nullptr) return head -> next;
        
        ListNode* fast = head -> next;
        ListNode* slow = head;
        
        while(fast != nullptr){
            slow = slow -> next;
            fast = fast -> next;
            if(fast != nullptr)
                fast = fast -> next;
        }
        return slow;
    }
};

int main() {
    

return 0;
}