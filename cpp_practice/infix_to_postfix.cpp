#include <bits/stdc++.h>
using namespace std;

string infix_to_postfix(string exp){

    //precedence map
    unordered_map<char, int> precedence;
    precedence['+'] = 1;
    precedence['-'] = 1;
    precedence['*'] = 2;
    precedence['/'] = 2;

    stack<char> op;
    string ans = "";

    for(int i = 0; i < exp.size(); i++){

        char ch = exp[i];

        // operand
        if(isalpha(ch) || isdigit(ch)){
            ans += ch;
        }

        // '(' push
        else if(ch == '('){
            op.push(ch);
        }

        // ')' pop until '('
        else if(ch == ')'){
            while(!op.empty() && op.top() != '('){
                ans += op.top();
                op.pop();
            }
            op.pop(); // pop '('
        }

        // operator
        else {
            while(!op.empty() && op.top() != '(' &&
                  precedence[op.top()] >= precedence[ch]){
                ans += op.top();
                op.pop();
            }
            op.push(ch);
        }
    }

    // pop remaining
    while(!op.empty()){
        ans += op.top();
        op.pop();
    }

    return ans;
}


// FIXED Stack class
class Stack{
    int *arr;
    int top;
    int size;
public:
    Stack(int size){
        arr = new int[size];
        top = -1;
        this->size = size;
    }
    bool push(int val){
        if(top == size - 1){
            cout<<"Stack Overflow"<<endl;
            return false;
        }
        arr[++top] = val;
        return true;
    }
    int pop(){
        if(top == -1){
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        return arr[top--];
    }
    bool isEmpty(){
        return top == -1;
    }
    bool isFull(){
        return top == size - 1;
    }
    void display(){
        for(int i = 0; i <= top; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main() {

    int no_of_strings = 0;
    cin >> no_of_strings;

    while(no_of_strings--){
        string s;
        cin >> s;
        cout << "Ans : " << infix_to_postfix(s) << endl;
    }

    return 0;
}
