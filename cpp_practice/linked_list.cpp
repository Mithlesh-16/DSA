#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next = NULL;

    Node(int data){
        this->data = data;
    }
    ~Node(){
        cout << "Node with Val : " << this->data << " deleted" << endl;
    }
};

// Insert at end (takes head by reference)
void insert_node(Node* &head, int val){
    Node* tmp = new Node(val);

    if(head == NULL){
        head = tmp;
        return;
    }

    Node* curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = tmp;
}

// Delete first occurrence
int delete_node(Node* &head, int val){
    if(!head) return -1;

    Node* curr = head;
    Node* prev = NULL;

    while(curr && curr->data != val){
        prev = curr;
        curr = curr->next;
    }

    if(!curr) return -1; // not found

    int x = curr->data;

    if(curr == head){
        head = head->next;
    }
    else{
        prev->next = curr->next;
    }

    delete curr;
    return x;
}

// ---------------- STACK USING LINKED LIST ---------------- //

class Stacks{
    Node* topNode;
public:
    Stacks(){
        topNode = NULL;
    }

    bool push(int val){
        Node* tmp = new Node(val);
        tmp->next = topNode;
        topNode = tmp;
        return true;
    }

    int pop(){
        if(topNode == NULL){
            cout << "Stack already Empty" << endl;
            return -1;
        }
        int val = topNode->data;
        Node* tmp = topNode;
        topNode = topNode->next;
        delete tmp;
        return val;
    }

    int top(){
        return topNode ? topNode->data : -1;
    }

    bool empty(){
        return topNode == NULL;
    }
};

// ---------------- QUEUE USING LINKED LIST ---------------- //

class Queue{
    Node* head;
    Node* tail;
public:
    Queue(){
        head = NULL;
        tail = NULL;
    }
    bool push(int val){
        Node* tmp = new Node(val);
        if(tail == NULL){
            head = tail = tmp;
            return true;
        }
        tail->next = tmp;
        tail = tmp;
        return true;
    }
    int pop(){
        if(head == NULL){
            cout << "Queue Already Empty" << endl;
            return -1;}
        Node* tmp = head;
        int val = head->data;
        head = head->next;
        if(head == NULL) tail = NULL; // queue empty now
        delete tmp;
        return val;
    }
    int front(){
        return head ? head->data : -1;
    }
    int size(){
        int cnt = 0;
        Node* curr = head;
        while(curr){
            cnt++;
            curr = curr->next;
        }
        return cnt;
    }
    bool empty(){
        return head == NULL;
    }
};

int main(){

    Node* head = NULL;
    insert_node(head, 10);
    insert_node(head, 20);
    insert_node(head, 30);
    cout << "Deleted: " << delete_node(head, 20) << endl;

    Stacks s;
    s.push(5);
    s.push(10);
    cout << "Popped from stack: " << s.pop() << endl;

    Queue q;
    q.push(11);
    q.push(22);
    cout << "Queue front: " << q.front() << endl;
    cout << "Queue pop: " << q.pop() << endl;

    return 0;
}
