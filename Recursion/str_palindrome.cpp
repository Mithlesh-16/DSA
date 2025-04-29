#include <iostream>
using namespace std;

bool str_palindrome( string &str, int &i){

    if(str[i] == str[str.size() - 1-i]){
    
        if(i > str.size() - 1-i) return 1;
        else  return str_palindrome(str,++i);

    }else return 0;
        

}

int main() {
    string str = "";
    cin>>str;
    int i = 0;
    cout<<str_palindrome(str,i);

return 0;
}