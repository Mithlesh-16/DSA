#include <iostream>
#include <map>
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

// By using Map method
// Time complexity : O(n)
ListNode* remove_duplicates(ListNode* head){
    ListNode* curr = head;
    ListNode* prev = nullptr;
    map <ListNode*, bool> visited;
    while(curr){
        if(visited[curr]) {
            ListNode* next_next = curr -> next;
            prev -> next = curr -> next;
            curr -> next = NULL;
            delete(curr);
            curr = next_next;
        }else{
            prev = curr;
            visited[curr] = 1;
            curr = curr -> next;
        }

    }
    return head;
}

// By iterative two times each 
// Time Complexity : O(n^2)
ListNode* remove_duplicates_2(ListNode* head){
    ListNode* curr = head;
    ListNode* prev = nullptr;
    while(curr){
        ListNode* temp = curr -> next;
        while(temp){
            if(temp -> val == curr -> val) {
                curr -> next ;
            }
        }
    }
}


int main() {




return 0;
}