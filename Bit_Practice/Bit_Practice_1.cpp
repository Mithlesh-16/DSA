#include<bits/stdc++.h>
using namespace std;
int main(){
    int a = 0,count = 0;
    cin>>a;
    while (a>0){
        if (a&1){
            count += 1;
        }


        a = a>>1;
    }
    cout<<count<<endl;

    // https://leetcode.com/problems/sum-of-two-integers/solutions/84278/a-summary-how-to-use-bit-manipulation-to-solve-problems-easily-and-efficiently

    return 0;
}