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
        cout<<"Destructor Called for "<<this->data<<endl;
    }
};

//insert before head
void insert_at_head(){

}

//insert after tail


int main() {


return 0;
}