#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//insertion - 
//deletion -
//searching -

class solution{

};

int main() {

    unordered_map<string, int> mp;

    //insertion
    //1st method
    pair<string, int> p1 = make_pair("mera", 1);
    mp.insert(p1);

    //2nd method
    pair<string, int> p2("naam", 2);
    mp.insert(p2);

    //3rd method
    mp["naam"] = 2;

    //searching
    cout<<mp["mera"]<<endl;
    cout<<mp.at("naam")<<endl;
    cout<<mp.at("babbar")<<endl;                //gives error trying to access undefined memory location
    cout<<mp["babbar"]<<endl;

    //to check presence 
    cout<<mp.count("Mithlesh")<<endl;

    mp.erase("naam");
    cout<<mp.size()<<endl;

    unordered_map<string,int> :: iterator it = mp.begin();
    while(it != mp.end()){
        cout<<it ->first<<" "<<it -> second<<endl;
    } 

return 0;
}