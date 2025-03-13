#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(2);
    v.push_back(1);

    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;


    cout<<binary_search(v.begin(),v.end(),6)<<endl;
    cout<<binary_search(v.begin(),v.end(),5)<<endl;

    cout<<lower_bound(v.begin(),v.end(),6)-v.begin()<<endl;
    cout<<upper_bound(v.begin(),v.end(),6)-v.begin()<<endl;

    string abcd ="abcd";
    reverse(abcd.begin(),abcd.end());
    cout<<abcd<<endl;


    rotate(v.begin(),v.begin()+1,v.end());
    cout<<"after Rotate"<<endl;
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;

    sort(v.begin(),v.end());                //based on Intro Sort
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}