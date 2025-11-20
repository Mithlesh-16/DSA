#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;
    node(int val){
        this->data = val;
        next = NULL;
    }
};

class Queue{
    node* currNode;
    node* head;
public:
    Queue(){
        currNode = NULL;
        head = NULL;
    }

    bool push(int val){
        node* tmp = new node(val);
        if(currNode == NULL){
            currNode = tmp;
            head = currNode;
            currNode->next = head;
            return true;
        }
        currNode->next = tmp;
        currNode = tmp;
        currNode->next = head;
        return true;
    }

    int pop(int val){
        if(!head){
            cout << "Queue is Empty !!" << endl;
            return -1;
        }
        node* tmp = head;
        node* prev = currNode;  // start prev at last node
        // Searching
        while(tmp->data != val){
            prev = tmp;
            tmp = tmp->next;
            if(tmp == head){
                cout << "Value not found!" << endl;
                return -1;
            }
        }
        // Case 1: Only one node
        if(tmp == head && tmp == currNode){
            int value = tmp->data;
            head = currNode = NULL;
            delete tmp;
            return value;
        }
        // Case 2: Deleting head
        if(tmp == head){
            head = head->next;
            currNode->next = head;
        }
        // Case 3: Deleting last node
        if(tmp == currNode){
            currNode = prev;
            currNode->next = head;
        }
        // General case
        prev->next = tmp->next;
        int value = tmp->data;
        delete tmp;
        return value;
    }

    void display(){
        if(!head){
            cout << "Queue is Empty !!" << endl;
            return;
        }
        node* tmp = head;
        cout << "Queue: ";
        do {
            cout << tmp->data << " ";
            tmp = tmp->next;
        } while(tmp != head);
        cout << endl;
    }
};

int main(){
    Queue q;
    int choice, val;

    while(true){
        cout << "\n----- Menu -----\n";
        cout << "1. Push\n";
        cout << "2. Pop (by value)\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter value: ";
                cin >> val;
                q.push(val);
                cout << "Inserted " << val << endl;
                break;

            case 2:
                cout << "Enter value to pop: ";
                cin >> val;
                {
                    int res = q.pop(val);
                    if(res != -1)
                        cout << "Popped: " << res << endl;
                }
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
