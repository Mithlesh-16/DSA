#include <iostream>
#include <optional>
using namespace std;

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



int main() {


    return 0;
}