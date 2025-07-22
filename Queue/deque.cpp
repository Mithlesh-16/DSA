#include <iostream>
using namespace std;

class Deque{
    int* arr;
    int size;
    int front;
    int back;

    public:
    Deque(int n){
        size = n;
        arr = new int[size];
        front = -1;
        back = -1;
    }


    bool pushFront(int x){
        if(front == -1){
            front = back = 0;
            arr[front] = x;
        }
        else if((front == 0 and back == size - 1) or (front - back == 1)){
            return false;
        }
        else if(front == 0 and back != size - 1){
            front = size - 1;
            arr[front] = x;
        }
        else{
            front --;
            arr[front] = x;
        }
        return true;
    }

    bool pushRear(int x){
        if(back == -1){
            front = back = 0;
            arr[back] = x;
        }
        else if((front == 0 and back == size - 1) or (front - back == 1)){
            return false;
        }
        else if(back == size - 1 and front != 0){
            back = 0;
            arr[back] = x;
        }
        else{
            back++;
            arr[back] = x;
        }
        return true;
    }

    int popRear(){
        int tmp = arr[back];
        if(front == -1){
            return -1;
        }
        else if(front == back){
            front = back = -1;
        }
        else if(back == 0){
            back = size - 1;
        }
        else{
            back --;
        }
        return tmp;
    }

    int popFront(){
        int tmp = arr[front];
        if(front == -1){
            return -1;
        }
        else if(front == back){
            front = back = -1;
        }
        else if(front == size -1){
            front = 0;
        }
        else {
            front ++;
        }
        return tmp;
    }
};

int main() {
    Deque dq(5);
    cout << "Push Front 10: " << dq.pushFront(10) << endl;
    cout<<endl;
    cout << "Push Front 20: " << dq.pushFront(20) << endl;
    cout<<endl;
    cout << "Push Rear 30: " << dq.pushRear(30) << endl;
    cout<<endl;
    cout << "Pop Rear: " << dq.popRear() << endl;
    cout<<endl;
    cout << "Pop Rear: " << dq.popRear() << endl;
    

    // cout << "Front Element: " << dq.getFront() << endl;
    // cout << "Rear Element: " << dq.getRear() << endl;
    // cout << "Pop Front: " << dq.popFront() << endl;
    // cout << "Is Empty: " << dq.isEmpty() << endl;
    // cout << "Is Full: " << dq.isFull() << endl;

return 0;
}