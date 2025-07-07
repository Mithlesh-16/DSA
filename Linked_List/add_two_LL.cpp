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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        

        ListNode* curr1 = l1;
        ListNode* curr2 = l2;


        int carry = 0;
        ListNode* prev1 = nullptr;
        ListNode* prev2 = nullptr;

        while(curr1 != nullptr and curr2 != nullptr){
            int sum = curr1 -> val + curr2 -> val + carry;
            if(sum >= 10){
                curr1 -> val = (sum - 10);
                carry = 1;
            }else{
                curr1 -> val = sum;
                carry = 0;
            }

            prev1 = curr1;
            curr1 = curr1 -> next;
            curr2 = curr2 -> next;
        }

        while(curr1 != nullptr){
            int sum = curr1 -> val + carry;
            if(sum >= 10){
                curr1 -> val = sum - 10;
                carry = 1;
            }else{
                curr1 -> val = sum;
                carry = 0;
            }
            prev1 = curr1;
            curr1 = curr1 -> next;
        }

        while(curr2 != nullptr){
            int sum = curr2 -> val + carry;
            if(sum >= 10){
                curr2 -> val = (sum -10);
                carry = 1;
            }else{
                curr2 -> val = sum;
                carry = 0;
            }

            prev1 -> next = curr2;
            prev1 = curr2;
            curr2 = curr2 -> next;
        }
        
        if(carry > 0){
            ListNode* next1  = new ListNode(carry);
            prev1 -> next = next1;
        }
        
        return l1;

    }
};

int main() {


return 0;
}