#include <bits/stdc++.h>
using namespace std;

string postfix_to_infix(string expr){
    stack<string> ans;
    for(int i = 0; i < expr.size(); i++){
        if(isalnum(expr[i])){
            ans.push(string() + expr[i]);
        }
        else{
            string b = ans.top();
            ans.pop();
            string a = ans.top();
            ans.pop();
            ans.push(a + expr[i] + b);
        }
    }
}

int main() {


return 0;
}