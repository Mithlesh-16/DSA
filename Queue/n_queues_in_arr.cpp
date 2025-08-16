#include <iostream>
#include <queue>
using namespace std;

class k_queue{
    int *arr;
    int *next;
    int *front;
    int *rear;
    int size;
    int q_cnt;
    int freespot = 0;

    public:
        k_queue(int size, int q_cnt){
            arr = new int[size];
            next = new int[size];
            front = new int[q_cnt];
            rear = new int[q_cnt];
            this -> size = size;
            this -> q_cnt = q_cnt;


            for(int i = 0; i < size; i++){
                next[i] = i+1;
            }
            next[size - 1] = -1;

            for(int i = 0; i < q_cnt; i++){
                front[i] = -1;
                rear[i] = -1;
            }

        }

        bool push_queue(int n, int q_no){
            //overflow
            if(freespot == -1){
                return false;
            }
            int index = freespot;
            if(front[q_no - 1] == -1){
                front[q_no - 1] = index;
            }
            else{
                next[rear[q_no - 1]] = index;
            }

            rear[q_no - 1] = index;
            freespot = next[index];
            arr[index] = n;
            next[index] = -1;   

            return true;
        }

        bool pop_queue(int q_no){
            //underflow 
            if(front[q_no - 1] == -1){
                return false;
            }
            
            int index = front[q_no - 1];
            front[q_no - 1] = next[index];

            next[index] = freespot;
            freespot = index;
            
            return true;
        }

        

        
};


int main(){

    k_queue q_grp(10, 3);

    q_grp.push_queue(10, 1);
    q_grp.push_queue(20, 1);
    q_grp.push_queue(30, 3);
    q_grp.push_queue(0, 2);
    q_grp.push_queue(9, 3);
    q_grp.push_queue(12, 2);
    q_grp.push_queue(5, 1);

    q_grp.pop_queue(1);
    q_grp.pop_queue(3);
    q_grp.pop_queue(1);
    q_grp.pop_queue(2);
    q_grp.pop_queue(3);
    q_grp.pop_queue(1);

    

}