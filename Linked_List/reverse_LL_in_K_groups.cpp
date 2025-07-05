#include <iostream>
using namespace std;


 //Definition for singly-linked list.
 class Node {
  public:
      int data;
      Node *next;
      Node() : data(0), next(nullptr) {}
      Node(int x) : data(x), next(nullptr) {}
      Node(int x, Node *next) : data(x), next(next) {}
  };
 
Node* kReverse_by_recursion(Node* head, int k){
    //base case
    if(head == nullptr || head -> next == nullptr){
        return head;
    }

    Node* curr = head;
    Node* prev = nullptr;
    Node* next_node = curr -> next;
    int cnt = 0;

    while(cnt < k and curr != nullptr){
        next_node = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next_node;
        cnt++;
    }

    //recursive call
    Node* chota_head = kReverse_by_recursion(curr, k);
    head -> next = chota_head;
    head = prev;

    return head;
    
}

Node* kReverse(Node* head, int k) {
    // Write your code here.
    int reversal_cnt = 1;
    int node_cnt = 0;
    Node* curr= head;
    while(curr != nullptr){
        node_cnt++;
        curr = curr -> next;
    }
    int total_reversal_cnt = node_cnt / k;

    curr = head;
    Node* prev = nullptr;
    Node* chota_head = head;
    Node* chota_tail = head;
    

    while(curr != nullptr && reversal_cnt <= total_reversal_cnt){
        int cnt = 0;
        while(cnt < k && curr != nullptr){

            Node* next_node = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next_node;

            cnt++;
        }

        chota_tail -> next = prev;
        chota_head -> next = curr;
        chota_tail = chota_head;
        chota_head = curr;
        
        
        if(reversal_cnt == 1){
            head = prev;
        }
        reversal_cnt ++;
    }
    return head;
}

int main() {


return 0;
}