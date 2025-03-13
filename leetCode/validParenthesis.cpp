#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool isValid(string s) {
            cin>>s;
            if (s.size()%2 != 0){
                cout<<"not divisible by 2"<<endl;
                return false;
            }
            else{
                int size = s.size();
                for(int i =0;i<size/2;i++){
                    if(s[i] == s[size-1 -i]){
                        continue;
                    }else{
                        return false;
                        cout<<"not same order"<<endl;
    
                    }
                }
            }
            return true;
        }
    };
    int main(){
        cout<<endl<<"Done";
        return 0;
    }