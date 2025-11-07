#include <iostream>
#include <stack>
#include <limits.h>
using namespace std;

class SpecialStack {
    public:
    stack<int> s;
    int mini;
        
    void push(int data) {
        if(s.empty()){
            s.push(data);
            mini = data;
        }else{
            if(data < mini){
                s.push(2*data - mini);
                mini = data;
            }else{
                s.push(data);
            }
        }  
    }

    void pop() {
        if(s.empty()){
            return ;
        }
        if(s.top() < mini){
            mini = 2*mini - s.top();
            s.pop();
        }else{
            s.pop();
        }
    }

    int top() {
        if(s.empty()) return -1;
        if(s.top() > mini){
            return s.top();
        }else{
            return mini;
        }
    }

    int getMin() {
        return mini;
    }  
};

int main() {


return 0;
}