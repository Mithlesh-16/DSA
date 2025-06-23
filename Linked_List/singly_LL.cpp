#include <iostream>
using namespace std;

// linked list class
class node
{
public:
    int data;
    node* next_node;

    // constructor
    node(int data)
    {
        this->next_node = NULL;
        this->data = data;
    }

    // destructor
    ~node()
    {
        // memory free
        int value = this->data;
        if (this->next_node != NULL)
        {
            delete next_node;
            this->next_node = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};

// insert before head
void insert_at_head(node* &head, int d)
{
    // new node create
    node* temp = new node(d);

    temp->next_node = head;
    head = temp;
}

// insert after head i.e. at tail
void insert_at_tail(node* &tail, int d)
{
    // new node created to insert
    node* temp = new node(d);

    tail->next_node = temp; // next_node = address of temp
    tail = temp;            // temp is the new tail
}

// insert in position
void insert_at_position(node* &head, node* &tail, int position, int d)
{
    node* temp = head;
    int cnt = 1;

    // insert at Start
    if (position == 1)
    {
        insert_at_head(head, d);
        return;
    }

    while (cnt < position - 1)
    {
        temp = temp->next_node;
        cnt++;
    }

    if (temp->next_node == NULL)
    {
        insert_at_tail(tail, d);
        return;
    }
    // creating a node for d
    node* node_to_insert = new node(d);

    node_to_insert->next_node = temp->next_node;
    temp->next_node = node_to_insert;
}

// delete any node
void delete_node(node *&head, node *&tail, int position)
{
    node* temp = head;
    int cnt = 1;

    // start node delete
    if (position == 1)
    {
        head = head -> next_node;
        // memory free start node
        temp->next_node = NULL;
        delete temp;
        temp = nullptr;     //to avoid after free bugs
        return;
    }
    while (cnt < position - 1)
    {
        temp = temp->next_node;
        cnt++;
    }
    node* temp2 = temp;
    temp2 = temp2->next_node;
    temp->next_node = temp2->next_node;
    // last node delete
    if (temp->next_node == NULL)
    {
        tail = temp;
    }
    // free Memory of deleted node
    temp2->next_node = NULL;
    delete temp2;
    temp2 = nullptr;    //to avoid after free bugs
}

// print
void print(node* &tail)
{
    node* temp = tail;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next_node;
    }
    cout << endl;
}

int main()
{
    // dynamic allocation
    // insert after tail
    node* node1 = new node(40);

    // tail pointer pointing towards node1
    node* tail = node1;

    insert_at_tail(tail, 30);
    insert_at_tail(tail, 20);
    insert_at_tail(tail, 10);
    insert_at_tail(tail, 0);

    print(node1); // as tail is pointing towards the NULL
                  // always start printing from start

    // insert before head
    node* node2 = new node(40);
    node* head = node2;
    node* tail2 = node2;
    insert_at_head(head, 30);
    insert_at_head(head, 20);
    insert_at_head(head, 10);
    insert_at_position(head, tail, 1, 25);  // at first position
    insert_at_position(head, tail2, 6, 50); // at last position

    print(head);

    delete_node(head, tail2, 3);
    print(head);
    delete_node(head, tail2, 1);
    print(head);
    delete_node(head, tail2, 4);
    print(head);
    delete_node(head, tail2, 3);
    print(head);

    cout << "head : " << head->next_node << " " << head->data << endl;
    cout << "tail : " << tail2->next_node << " " << tail2->data << endl;

    // static allocation
    //  node node3(30);
    //  node node4(40);
    //  cout<<node3.next_node<<" "<<node3.data<<endl;
    //  cout<<node4.next_node<<" "<<node4.data<<endl;

    return 0;
}