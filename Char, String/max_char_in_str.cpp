#include<iostream>
#include <vector>
using namespace std;

int main(){
    string new_str ="";
    cin>> new_str;
    char count_str[new_str.size()] = {0};
    for (int i =0; i<new_str.length(); i++){
        char temp = new_str[i];
        for (int j = 0; j<new_str.length(); j++){
            if (temp == new_str[j]){
                count_str[j] += 1;
            }
        }
    }
    //find Max
    int Max = 0;
    char c = ' ';
    for (int i = 0; i<new_str.length(); i++){
        if (count_str[i] > Max){
            Max = count_str[i];
            c = new_str[i];
        }
    }
    cout<<"Max Occurance = "<<c<<endl;

    return 0;
}