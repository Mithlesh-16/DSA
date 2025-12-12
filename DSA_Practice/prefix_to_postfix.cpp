#include <bits/stdc++.h>
using namespace std;

string prefix_to_postfix(string expr){
    stack<string> ans;
    reverse(expr.begin(), expr.end());

    for(int i = 0; i  < expr.size(); i++){
        
        if(isalnum(expr[i])){
            ans.push(string() + expr[i]);
        }
        else{
            string a = ans.top();
            ans.pop();
            string b = ans.top();
            ans.pop();
            ans.push(b + a + expr[i]);
        }

    }

    return ans.top();

}

int main(){

    int n; 
    cin>>n;
    while(n --){
        string s;
        cin>>s;
        cout<<"Ans : "<<prefix_to_postfix(s)<<endl;
        cout<<endl;
    }


    return 0;
}