#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class compare{
    public:
    bool operator()(ListNode* a, ListNode* b){
        if(a and b)
            return a -> val > b -> val;
        else return false;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

        //step 1: push all heads to the minHeap
        for(int i = 0; i < lists.size(); i++){
            if(lists[i])
            minHeap.push(lists[i]);
        }

        while(minHeap.size()){
            if(head == NULL){
                ListNode* tmp = minHeap.top();
                head = tmp;
                tail = tmp;
                if(tmp and tmp -> next){
                    minHeap.push(tmp -> next);
                }
            }
            else{
                ListNode* tmp = minHeap.top();
                tail -> next = tmp;
                tail = tail -> next;
                if(tmp and tmp -> next){
                    minHeap.push(tmp -> next);
                }
            }
            minHeap.pop();
        }
        return head;
    }
};

int main() {

    


    return 0;
}