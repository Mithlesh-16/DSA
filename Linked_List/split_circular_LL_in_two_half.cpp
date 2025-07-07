#include <iostream>
#include <vector>
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

vector<ListNode*> split_circular_LL(ListNode* head){
    vector<ListNode*> result;
    result.push_back(head);

    if(head == nullptr) return result;
    if(head -> next == nullptr or head -> next == head) return result;

    ListNode* slow = head;
    ListNode* fast = slow -> next;
    while(fast != head and fast-> next != head){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    ListNode* mid = slow;
    
    //first LL
    ListNode* head2 = slow -> next;
    slow -> next = nullptr;
    
    //second LL
    
    
    result.push_back(head2);
    return result;
}

int main() {


return 0;
}