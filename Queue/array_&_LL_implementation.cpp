#include <iostream>
#include <optional>
using namespace std;

//array implementation of Queue
class Queue{
    int *arr;
    int front;
    int back;
    int size;

    public:
    Queue(int size){
        this -> size = size;
        arr = new int[size];
        front = 0;
        back = 0;
    }

    void push(int data){
        if(back == size){
            cout<<"queue full !!"<<endl;
        }
        arr[back] = data;
        back ++;
    }

    void pop(){
        if(front < back){
            front ++;
        }else{
            cout <<"Queue is empty, cannot pop element." << endl;
        }
    }

    optional<int> get_front(){
        if(front < back){
            return arr[front];
        }
        else
            return std::nullopt;
    }

    optional<int> get_back(){
        if(front < back){
            return arr[back - 1];
        }else
            return nullopt;
    }

    int size(){
        return back - front;
    }

    bool empty(){
        return front == back;
    }

};

// Linked List Implementation of Queue
class Node{

    public:

    int data;
    Node* next;

    Node(int n){
        this -> data = n;
        this -> next = nullptr;
    }
    Node(int n, Node* next){
        this -> data = n;
        this -> next = next;
    }
    
    ~Node(){
        
    }
};

class Queue{
    Node* head;
    Node* tail;
    int position;
    int size;

    public:
    Queue(int size){
        head = tail = nullptr;
        this -> size = size;
        position = 0;
    }

    bool push(int x){
        if(head == nullptr){
            head = tail = new Node(x);
        }
        else if(position == size){
            return false;
        }
        else{
            tail -> next = new Node(x);
            tail = tail -> next;
        }

        position ++;
        return true;
    }

    bool pop(){
        if(head == nullptr){
            return false;
        }
        else if(head == tail){
            head = tail = nullptr;
        }
        else{
            Node* tmp = head;
            head = head -> next;
            delete tmp;
        }
        return true;
    }

    int getFront(){
        if(head == nullptr){
            return -1;
        }
        return head -> data;
    }

    int getBack(){
        if(tail == nullptr){
            return -1;
        }
        return tail -> data;
    }
};

int main() {


    return 0;
}