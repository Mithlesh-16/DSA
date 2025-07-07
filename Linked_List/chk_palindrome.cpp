#include <iostream>
#include <vector>
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

class Solution{
    private:
    ListNode* reverse_LL(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr){
            ListNode* next_node = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next_node;
        }
        return prev;
    }

    public:
    bool chk_palindrome(ListNode* head){

        // i) find Middle
        // ii) reverse second half
        // iii) compare both parts
        // iv) reverse again and make it same as before

        if(head == NULL) return false;
        if(head -> next == NULL) return true;

        // finding Middle
        ListNode* slow = head;
        ListNode* fast = slow -> next;
        while(fast and fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* Middle = slow;

        ListNode* head2 = reverse_LL(Middle -> next);

        // Compare
        while(head and head2){
            if(head -> val != head2 -> val) return false;
            head = head -> next;
            head2 = head2 -> next;
        }

        // Again, Reverse the second half 
        head2 = reverse_LL(Middle -> next);
        Middle -> next = head2;


        return true;
    }

    // Solve it by moving values to an array, 
    // then, check palindrome;
    bool chk_palindrome_2(ListNode* head){
        vector<int> list;
        ListNode* curr = head;
        while(curr){
            list.push_back(curr -> val);
            curr = curr -> next;
        }

        for(int i = 0, j = list.size() - 1; i <= j; i++, j--){
            if(list[i] != list[j]) return false;
        }

        return true;
    }
};



int main() {


return 0;
}