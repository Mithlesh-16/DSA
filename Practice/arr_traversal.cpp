#include <bits/stdc++.h>
using namespace std;

// ------------------- STACK FUNCTIONS -------------------
void push(vector<char> &st, char ch){
    st.push_back(ch);
}
char pop(vector<char> &st){
    char top = st.back();
    st.pop_back();
    return top;
}
char top_ele(vector<char> &st){
    return st.back();
}

// ------------------- PRECEDENCE ------------------
int precedence(char ch){
    if(ch == '+' || ch == '-') return 1;
    if(ch == '*' || ch == '/') return 2;
    if(ch == '^') return 3;
    return 0;
}

// ------------------- INFIX TO POSTFIX -------------
string infixToPostfix(string expr){
    vector<char> st;   // stack
    string ans = "";

    for(int i = 0; i < expr.size(); i++){
        char ch = expr[i];

        // Operand
        if(isalnum(ch)){
            ans += ch;
        }
        // Opening bracket
        else if(ch == '('){
            push(st, ch);
        }
        // Closing bracket
        else if(ch == ')'){
            while(!st.empty() && top_ele(st) != '('){
                ans += pop(st);
            }
            pop(st); // remove '('
        }
        // Operator
        else{
            while(!st.empty() && precedence(top_ele(st)) >= precedence(ch)){
                ans += pop(st);
            }
            push(st, ch);
        }
    }
    // Pop remaining operators
    while(!st.empty()){
        ans += pop(st);
    }
    return ans;
}

// ------------------- EVALUATE POSTFIX -----------------------
int evaluatePostfix(string post){
    vector<int> st;

    for(int i = 0; i < post.size(); i++){
        char ch = post[i];

        // If digit, push value
        if(isdigit(ch)){
            st.push_back(ch - '0');      // convert char to int
        }
        else{
            int b = st.back(); st.pop_back();
            int a = st.back(); st.pop_back();
            int res = 0;

            switch(ch){
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
                case '^': res = pow(a, b); break;
            }

            st.push_back(res);
        }
    }

    return st.back();
}

// ------------------- MAIN -------------------
int main(){

    string exp;
    cout << "Enter Infix Expression : ";
    cin >> exp;

    string post = infixToPostfix(exp);
    cout << "Postfix Expression : " << post << endl;

    cout << "Evaluation Result : " << evaluatePostfix(post) << endl;

    return 0;
}
