#include <iostream>
using namespace std;

// doubly LL
class node
{
public:
    int data;
    node *prev;
    node *next;

    // constructor
    node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    // destructor
    ~node()
    {
        if(next != NULL){
            delete(next);
            next = NULL;
        }
        cout<<"memory free for node with data : "<<this-> data<<endl;
    }
};

// insert before head
void insert_at_head(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

// insert at tail
void insert_at_tail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

// delete at any position
void delete_position(node *&head, node *&tail, int position)
{
    node *temp = head;
    if (position == 1)
    {
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    node *temp2 = temp->next;
    temp->next = temp2->next;
    if (temp2->next == NULL)
    {
        delete temp2;
        tail = temp;
        return;
    }
    temp2->next->prev = temp;
    temp2->prev = NULL;
    temp2->next = NULL;

    delete temp2;
}

// insert at position
void insert_at_position(node *&head, node *&tail, int position, int d)
{
    node *temp3 = new node(d);
    if (position == 1)
    {
        insert_at_head(head, d);
        return;
    }

    node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp -> next;
        // cout<<"temp -> next : "<<temp -> next -> data<<endl;
        cnt++;
    }

    // cout<<"temp : "<<temp->data<<endl;
    if(temp -> next == NULL){
        insert_at_tail(tail, d);
        return;
    }

    temp3->prev = temp;
    temp3->next = temp->next;
    temp->next->prev = temp3;
    temp->next = temp3;

    if (temp3->next == NULL)
    {
        tail = temp3;
    }
}

// print
void print(node *&head)
{
    node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    node *node1 = new node(10);
    node *tail = node1;
    node *head = node1;

    insert_at_head(head, 20);
    insert_at_head(head, 30);
    insert_at_head(head, 40);
    insert_at_head(head, 50);
    insert_at_head(head, 60);
    print(head);

    insert_at_tail(tail, 90);
    insert_at_tail(tail, 80);
    insert_at_tail(tail, 70);
    insert_at_tail(tail, 85);
    print(head);

    insert_at_position(head, tail, 4, 44);
    print(head);
    insert_at_position(head, tail, 5, 55);
    print(head);
    insert_at_position(head, tail, 6, 66);
    print(head);
    insert_at_position(head, tail, 1, 11);
    print(head);

    delete_position(head, tail, 4);
    print(head);
    delete_position(head, tail, 5);
    print(head);
    delete_position(head, tail, 1);
    print(head);
    delete_position(head, tail, 11);
    print(head);
    insert_at_position(head, tail, 11, 111);
    print(head);
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;

    return 0;
}