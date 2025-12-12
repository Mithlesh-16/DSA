#include <iostream>
using namespace std;

//linked list class
class node{
    public:
        int data;
        node* next_node = NULL;
    node(int d){
        this->data = d;
    }

    ~node(){
        cout<<"Destructor Called : "<<this-> data<<endl;
        if(this-> next_node != NULL){
            delete next_node;
            next_node = NULL;
        }
    }
};

//insert before head
void insert_at_head(node* &head, int d){
    node* temp = new node(d);
    temp -> next_node = head;
    head = temp;
}

//insert after tail
void insert_at_tail(node* &tail, int d){
    node* temp = new node(d);
    tail -> next_node = temp;
    tail = temp;
}

//insert at any position
void insert_at_position(node* &head,node* &tail, int position, int d){
    node* temp = head;
    if(position == 1){
        insert_at_head(head, d);
        return;
    }
    int cnt = 1;
    while(cnt < position - 1){
        temp = temp-> next_node;
        cnt++;
    }
    node* temp2 = new node(d);
    temp2 ->next_node = temp ->next_node;
    temp ->next_node = temp2;
    if(temp2 ->next_node == NULL){
        tail = temp2;
    }
}

//delete any node 
void delete_position(node* &head,node* &tail, int position){
    node* temp = head;
    //start node delete
    if(position == 1){
        head = head-> next_node;
        temp -> next_node = NULL;
        delete temp;
        temp = nullptr;     //avoid after free use
        return;
    }

    //any node in middle or last except start
    int cnt = 1;
    while(cnt < position - 1){
        temp = temp-> next_node;
        cnt++;
    }
    node *prev = temp;
    node *curr = prev->next_node;
    prev-> next_node = curr->next_node;
    if(curr-> next_node == NULL){
        tail = prev;
    }
    curr->next_node = NULL;
    delete curr;
    curr = nullptr;     //avoid after free use 
}

//print the linked list
void print(node* &head){
    node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next_node;
    }
    cout<<endl;
}

int main() {

    node* head = new node(10);
    //insert at head
    insert_at_head(head, 20);
    insert_at_head(head, 30);
    insert_at_head(head, 40);
    insert_at_head(head, 50);
    insert_at_head(head, 60);
    insert_at_head(head, 70);

    print(head);

    head = nullptr;
    head = new node(10);
    node* tail = head;
    insert_at_tail(tail,20);
    insert_at_tail(tail,30);
    insert_at_tail(tail,40);
    insert_at_tail(tail,50);
    insert_at_tail(tail,60);
    insert_at_tail(tail,70);

    print(head);

    //delete node(s)
    delete_position(head, tail, 2);
    print(head);
    delete_position(head, tail, 1);
    print(head);
    delete_position(head, tail, 5);
    print(head);
    insert_at_position(head, tail, 4, 44);
    print(head);
    insert_at_position(head, tail, 1, 11);
    print(head);
    insert_at_position(head, tail, 6, 66);
    print(head);
    insert_at_position(head, tail, 8, 88);
    print(head);
    delete_position(head, tail, 8);
    print(head);
    cout<<head->data<<" "<<head->next_node<<" ";
    cout<<head->next_node->next_node->data<<endl;
    cout<<tail->data<<" "<<tail->next_node<<endl;

return 0;
}