#include <iostream>
#include <string>
using namespace std;

bool check_duplicate(string s){
    char prev_char = s[0];
    for (int i = 1; i<s.size(); i++){
        if(prev_char == s[i]){
            s.replace(i-1,2,"");
            cout<<"s = "<<s<<" ";
            return 1;
        }
        prev_char = s[i];
    }
    return 0;
}

int main() {
    string s1;
    getline(cin,s1);
    int flag = 1;
    while(flag){
        cout<<"s1 = "<<s1<<" ";
        // find and remove duplicates
        char prev_char = s1[0],curr_char =' ';
        flag = 0;
        for(int i = 1; i<s1.size(); i++){
            curr_char = s1[i];
            if (prev_char == curr_char){
                s1.replace(i-1,2,"");
                // cout<<s1<<" ";
                flag = 1;
                break;
            }
            prev_char = curr_char;
        }

    }
    cout<<s1<<endl;

    

return 0;
}