#include <iostream>
using namespace std;

int main() {

    string s =  "";
    cin>>s;
    int arr[26] = {0};

    for(int i = 0; i<s.size(); i++){
        arr[s[i]-'A'] +=1;
        cout<<"arr : "<<arr[s[i] - 'A']<<" "<<s[i] - 'A'<<endl;
    }
    string s1 = s;
    int i = 0;
    for(int j = 0; j < 26 && i <= s.size()/2 ; j++){
        for(; i <= s.size()/2 && arr[j] > 1; i++){
            s1[i] = 'A' + j;
            arr[j]--;
            cout<<"i : "<<i<<" s1 : "<<s1<<endl;
            if(arr[j] > 0) s1[s.size() - 1 - i] = 'A' + j;
            cout<<"size - i : "<<s.size() - 1 - i<<" s1 : "<<s1<<endl;
            arr[j]--;
        }
            cout<<" after size - i : "<<s.size() - 1 - i<<" s1 : "<<s1<<endl;
        if(i  == s.size() - 1 - i && arr[j] > 0){
            cout<<"size - i : "<<s.size() - 1 - i<<" s1 : "<<s1<<endl;
            s1[i] = 'A' + j;
            i++;
        }
    }
    cout<<s1<<endl;


return 0;
}