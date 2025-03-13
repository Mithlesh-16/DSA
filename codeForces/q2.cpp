#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,i=0;
    cin>>t;
    while(i<t){
        string word;
        string newWord;
        cin>>word;
        newWord =word;
        long int size =word.size();
        for(int j =0;j<size-1;j++){
            if(word[j]==word[j+1]){
                newWord = word[0];
                if(j<size-2)
                newWord+=word.substr(j+2);
                cout<<newWord<<endl;
            }
        }
        if(newWord[0] == newWord[1]){
            newWord = newWord.substr(1);
            cout<<newWord<<endl;
        }
        if(size==1){
            newWord = word[0];
        }
        cout<<newWord.size()<<endl;





        i++;
    }


    return 0;
}