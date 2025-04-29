#include <bits/stdc++.h>
using namespace std;

int fibo(int n){
    // Base Case
    if (n == 2 || n == 1) return 1;  
    
    //Recursive Relation
    else return fibo(n-1) + fibo(n-2);
}

int main() {
    
    //fibonaaci nth
    int n; 
    cin>>n;
    cout<<fibo(n);



    return 0;
}