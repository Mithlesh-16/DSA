#include <iostream>
using namespace std;

string say_digits(int n, string arr[]){
    if(n == 0) return "";
    
    return say_digits(n/10, arr) +arr[n%10] + " ";
}

int main() {

    int n;
    cin>>n;
    string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    cout<<say_digits(n,arr)<<endl;

return 0;
}