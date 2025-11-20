#include <bits/stdc++.h>
using namespace std;

int prefix_eval(string exp){
    stack<int> s;
    reverse(exp.begin(), exp.end());

    for(int i = 0; i < exp.size(); i++){
        if(exp[i] == '+' or exp[i] == '-' or exp[i] == '*' or exp[i] == '/'){
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();

            if(exp[i] == '+') s.push(a + b);
            else if(exp[i] == '-') s.push(a - b);
            else if(exp[i] == '*') s.push(a * b);
            else s.push(a / b);

        }
        else{
            s.push(exp[i] - '0');
        }
    }

}

int main() {

    string s;
    cout<<"Prefix expression to Evaluate : "; 
    cin>>s;

    cout<<"Ans : "<<prefix_eval(s)<<endl;

return 0;
}