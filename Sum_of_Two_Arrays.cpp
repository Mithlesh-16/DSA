#include <bits/stdc++.h>
using namespace std;


void reverse(vector <int> v){
    int s = 0, e = v.size() -1;
    while(s <= e){
        swap(v[s],v[e]);
        s++;
        e--;
    }
    
    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> a1 = {1, 2, 3, 4}, a2 = {9, 8};
    int s1 = a1.size() - 1, s2 = a2.size() - 1;
    vector<int> sum;
    int carry = 0;

    while (s1 >= 0 && s2 >= 0)
    {
        int val = a1[s1] + a2[s2] + carry;
        sum.push_back(val % 10);
        carry = val / 10;

        s1--;
        s2--;
    }

    //first Case
    while(s1 >= 0){
        int val = a1[s1] + carry;
        sum.push_back(val%10);
        carry = val/10;
        s1--;
    }

    //Second Case
    while(s2 >= 0){
        int val = a2[s2] + carry;
        sum.push_back(val%10);
        carry = val/10;
        s2--;
    }

    //third Case
    if(carry>0){
        sum.push_back(carry);
    }

    reverse(sum);


    return 0;
}