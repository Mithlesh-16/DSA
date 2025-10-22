#include <iostream>
using namespace std;

int main(){

    int t = 0;
    cin>>t;
    while(t--){

        int winners = 0, losers = 0, teams = 0;
        cin>>teams;
        winners = teams;
        int matches = 0, current_losers = 0;
        while(winners != 1 or losers != 1){
            //winners
            matches += winners/2;
            current_losers = winners/2;
            winners = winners - winners/2;
            
            //losers
            matches += losers/2;
            losers = losers - losers/2;
            losers += current_losers;
            current_losers = 0;
        }

        cout<<matches+1<<endl;

    }
    return 0;
}