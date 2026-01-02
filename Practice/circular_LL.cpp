#include <iostream>
using namespace std;

// Singly Linked list or Doubly Linked list can be made Circular Linked list by connecting last and first nodes respectively.
// Singly-Circular Linked list
class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

// insert at head
void insert_at_head(node *&head, node *&tail, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head = temp;
    tail->next = head;
}

// insert at tail
void insert_at_tail(node *&head, node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
    tail->next = head; // for making it circular linked list
}

// insert at any position
void insert_at_position(node *&head, node *&tail, int position, int d)
{
    node *temp = head;
    if (position == 1)
    {
        insert_at_head(head, tail, d);
        return;
    }
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
    }
    if (temp->next == head)
    {
        insert_at_tail(tail, head, d);
        return;
    }
    node *temp2 = new node(d);
    temp2->next = temp->next;
    temp->next = temp2;
}

// delete any node
void delete_node(node *&head, int position)
{
}

// print Circular Linked list
void print(node *&head)
{
    node *temp = head;
    cout << temp->data << " ";
    temp = temp->next;
    while (temp != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    node *node1 = new node(10);
    node *head = node1;
    node *tail = node1;
    insert_at_head(head, tail, 20);
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;
    insert_at_head(head, tail, 30);
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;
    insert_at_head(head, tail, 40);
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;
    insert_at_head(head, tail, 50);
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;
    insert_at_head(head, tail, 60);
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;
    print(head);

    insert_at_tail(head, tail, 70);
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;
    insert_at_tail(head, tail, 80);
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;
    insert_at_tail(head, tail, 90);
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;
    insert_at_tail(head, tail, 100);
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;
    insert_at_tail(head, tail, 110);
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;
    print(head);

    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;
    cout << "tail -> next -> data : " << tail->next->data << endl;

    return 0;
}