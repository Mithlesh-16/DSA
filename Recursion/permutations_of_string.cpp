#include <iostream>
using namespace std;

void str_permut(string str, int &i){
    if(i == str.size()-1){
        return;
    }
    //swap
    for(int j = i; j<str.size()-1; j++){
        cout<<str<<" ";
        char c = str[j];
        str[j] = str[j + 1];
        str[(j + 1)] = c;
        
        str_permut(str, ++i);
    }
}

int main() {
    string str = "";
    cin>>str;
    int i = 0;
    str_permut(str, i);
    

return 0;
}