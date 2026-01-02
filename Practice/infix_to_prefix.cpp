#include <bits/stdc++.h>
using namespace std;

string infix_to_prefix(string expr){
    //precedence map
    unordered_map<char, int> precedence;
    precedence['+'] = 1;
    precedence['-'] = 1;
    precedence['*'] = 2;
    precedence['/'] = 2;

    stack<char> op;
    string ans = "";

    reverse(expr.begin(), expr.end());

    for(int i = 0; i < expr.size(); i++){
        char ch = expr[i];

        // swap every '(' from ')'
        if(ch == '(') ch = ')';
        else if(ch == ')') ch = '(';

        if(isalpha(ch) or isdigit(ch)){
            ans += ch;
        }
        else if(ch == '('){
            op.push(ch);
        }
        else if(ch == ')'){
            while(!op.empty() and op.top() != '('){
                ans += op.top();
                op.pop();
            }
            op.pop();
        }
        else{
            while(!op.empty() && op.top() != '(' && precedence[op.top()] >= precedence[ch]){
                ans += op.top();
                op.pop();
            }
            op.push(ch);
        }
    }

    while(!op.empty()){
        ans += op.top();
        op.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {

    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        cout<<"Ans : "<<infix_to_prefix(s)<<endl;
        cout<<endl;
    }

return 0;
}