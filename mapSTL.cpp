#include<iostream>
#include<map>

//Every key is Unique
using namespace std;
int main(){
    map<int,string> m;
    m[1] ="babbar";
    
    m[2] = "love";
    m[13] = "kumar";

    m.insert({5,"Bheem"});

    cout<<"before Erase : "<<endl;
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    //sorted in case of map
    cout<<endl;

    cout<<"finding 13 ="<<m.count(13)<<endl;
    cout<<"finding -13 ="<<m.count(-13)<<endl;

    m.erase(13);
    cout<<"after Erase : "<<endl;
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    auto it = m.find(5);        //returns Iterator
    for(auto i =it;i!=m.end();i++){
        cout<<(*i).first<<endl;
    }




    return 0;
}