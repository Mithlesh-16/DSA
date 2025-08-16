#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

string first_non_repeating_char(string s){
    
    queue<char> q;
    map<char, int> mp;

    for(int i = 0; i < s.size(); i++){
        mp[s[i]] ++;
        q.push(s[i]);

        // pop the duplicates till now in the queue
        while(!q.empty()){
            if(mp[q.front()] > 1){
                q.pop();
            }
            else{
                s[i] = q.front();
                break;
            }
        }
        if(q.empty()){
            s[i] = '#';
        }
    }

    return s;
}

int main() {

    cout<<"enter the string here : "<<endl;
    string s;
    cin>>s;

    cout<<first_non_repeating_char(s);

    return 0;
}