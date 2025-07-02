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
    private:
    ListNode* reverse_recursively(ListNode* head){
        //base case
        if(head == nullptr || head -> next == nullptr){
            return head;
        }

        ListNode* chhota_head = reverse_recursively(head -> next);
        
        head -> next -> next = head;
        head -> next = nullptr;

        return chhota_head;

    }
    public:
    ListNode* solve(ListNode* &head){

    }
};

int main() {

    


return 0;
}