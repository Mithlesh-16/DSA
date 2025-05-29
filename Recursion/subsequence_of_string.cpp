#include <iostream>
using namespace std;
#include <string>
#include <vector>

void subsequence_of_string(string &s1, string output, vector<string> &result, int index){
    if(index>=s1.size()){
        result.push_back(output);
        return;
    }

    //exclude
    subsequence_of_string(s1, output, result, index+1);
    //include
    output+= s1[index];
    subsequence_of_string(s1, output, result, index+1);
}

int main() {

    string s1 = "";
    vector<string> result;
    string output="";
    cin>>s1;
    subsequence_of_string(s1, output, result, 0);
    for(int i = 0; i<result.size(); i++){
        cout<<result[i];
        cout<<endl;
    }
    cout<<endl;



return 0;
}