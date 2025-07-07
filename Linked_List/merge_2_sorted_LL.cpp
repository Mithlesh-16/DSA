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

//leetcode solution here
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        ListNode* head1 = list1;
        ListNode* prev1 = nullptr;
        int cnt = 1;

        while (list1 != nullptr and list2 != nullptr) {

            if (list1->val >= list2->val) {

                if(cnt == 1 and list1 -> val > list2 -> val) 
                    head1 = list2;

                //check if there are more nodes in which values are same as this node value
                while (list1 != nullptr and list1->val == list2->val) {    
                    prev1 = list1;
                    list1 = list1->next;
                }
                
                ListNode* next_node2 = list2->next;
                if (prev1 != nullptr)
                    prev1->next = list2;
                list2->next = list1;
                prev1 = list2;
                list2 = next_node2;

            }

            else if (list1->val < list2->val) {

                //check if upto which node value is same as list1 node value
                while(list1 != nullptr and list1 -> val < list2 -> val){
                    prev1 = list1;
                    list1 = list1 -> next;
                }
                
                ListNode* next_node2 = list2->next;
                prev1->next = list2;
                list2->next = list1;
                prev1 = list2;
                list2 = next_node2;
            }
            cnt++;
        }

        //check if list2 is nullptr or not 
        while (list2 != nullptr) {
            if (prev1 != nullptr){
                prev1->next = list2;
                prev1 = list2;
            }
            list1 = list2;
            list2 = list2->next;
        }
        return head1;
    }
};


// Done by SLIDING WINDOW Concept
class Solution_2{
    public:
    ListNode* solve(ListNode* first, ListNode* second){

        ListNode* curr1 = first;
        ListNode* next1 = curr1 -> next;
        ListNode* curr2 = second;
        ListNode* next2 = curr2 -> next;

        while(next1 and curr2){
            if(curr2 -> val < next1 -> val and curr2 -> val > curr1 -> val){
                curr1 -> next = curr2;
                curr2 -> next = next1;

                //updating curr1 and curr2;
                curr1 = curr2;
                curr2 = next2;
            }
            else{
                curr1 = next1;
                next1 = next1 -> next;
                
                if(next1 == NULL){
                    curr1 -> next = curr2;
                    return first;
                }
            }
        }

    }

    ListNode* merge_sorted_LL(ListNode* head1, ListNode* head2){
        
        if(head1 == NULL) return head2;
        if(head2 == NULL) return head1;
        
        if(head1 -> next == NULL) {
            head1 -> next = head2;
            return head1;
        }

        ListNode* ans = head1;

        if(head1 -> val >= head2 -> val) ans = solve(head1, head2);
        else ans = solve(head2, head1);

        return ans;
    }
};

int main() {
    


return 0;
}