#include <bits/stdc++.h>
using namespace std;


int postfix_eval(string expr){
    stack<int> s;

    unordered_map<char, int> precedence;
    precedence['+'] = 1;
    precedence['-'] = 1;
    precedence['*'] = 2;
    precedence['/'] = 2;

    for(int i = 0; i < expr.size(); i++){
        if(expr[i] == '+' or expr[i] == '-' or expr[i] == '*' or expr[i] == '/'){
            if(s.size() != 0){
                int b = s.top();
                s.pop();

                int a = s.top();
                s.pop();

                if(expr[i] == '+') s.push(a + b);
                else if(expr[i] == '-') s.push(a - b);
                else if(expr[i] == '*') s.push(a * b);
                else s.push(a / b);
                cout<<s.top()<<endl;
            }
        }
        else{
            s.push(expr[i] - '0');
        }
    }
    cout<<"Ans : ";
    return s.top();
}

int main() {

    string s;
    cout<<"Enter PostFix Expression to Evaluate : ";
    cin>>s;
    
    cout<<postfix_eval(s)<<endl;

return 0;
}