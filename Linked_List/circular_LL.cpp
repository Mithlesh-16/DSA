#include <iostream>
using namespace std;

//in Circular Linked-List there is no head present !! 
//Only Tail here !! As we can track the whole Linked-List with the help of one node;
class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }

    //destructor
    ~Node(){

        //this is for continuous deletion, i.e. for deleting whole linked list starting from deleting node here!!
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout<<"Memory free for node with data : "<<this -> data<<endl;
    }
};

//insert at any position as there is no head here
void insert_Node(Node* &tail, int element, int d ){

    //assuming that the element is present in the list
    Node* node_to_insert = new Node(d);
    Node* temp = tail;

    //empty list
    if(tail == NULL){
        node_to_insert -> next = node_to_insert;
        tail = node_to_insert;
        return;
    }

    //non-empty list
    while(temp-> data != element){
        temp = temp -> next;
    }
    node_to_insert -> next = temp -> next;
    temp -> next = node_to_insert;

    
}

//deletion
void delete_Node(Node* &tail, int value){
    Node* temp = tail;

    //if tail is empty
    if(tail == NULL){
        cerr<<"Error : No list found"<<endl; 
    }

    // 1 node Linked_List
    if(tail -> next == tail && value == tail -> data){
        tail -> next = NULL;
        delete tail;
        tail = nullptr;
        return;
    }
    //2 or more nodes linked list
    if(tail -> data == value){
        tail = temp -> next;
    }
    while(temp -> next -> data != value){
        temp = temp -> next;
    }
    Node* Node_to_delete = temp -> next;
    temp -> next = Node_to_delete -> next;
    
    Node_to_delete -> next = NULL;
    delete Node_to_delete;
}

//printing the list
void print(Node* &tail){

    //if empty linked list is passed
    if(tail == NULL){
        cout<<"LIST IS EMPTY !! "<<endl;
        return;
    }

    Node* temp = tail;
    cout<<temp -> data<<" ";
    temp = temp -> next;
    while(temp != tail){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main() {
    //tail is created here !!
    Node* tail = NULL;

    //insertion
    insert_Node(tail, 4, 3);
    print(tail);
    insert_Node(tail, 3, 4);
    print(tail);
    insert_Node(tail, 4, 5);
    print(tail);
    insert_Node(tail, 5, 6);
    print(tail);
    insert_Node(tail, 4, 8);
    print(tail);
    insert_Node(tail, 6, 7);
    print(tail);

    //deletion
    delete_Node(tail, 6);
    print(tail);
    delete_Node(tail, 7);
    print(tail);
    delete_Node(tail, 3);
    print(tail);

return 0;
}