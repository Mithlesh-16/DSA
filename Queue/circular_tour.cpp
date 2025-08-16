#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int circular_tour(vector<int> gas, vector<int> cost){
    int start = 0, deficit = 0, balance = 0;
    for(int i = 0; i < gas.size(); i++){
        balance += gas[i] - cost[i];
        if(balance < 0){
            deficit += balance;
            balance = 0;
            start = i+1;
        }
    }

    if(balance + deficit >= 0){
        return start;
    }
    return -1;
}

int main(){

    vector<int> gas;
    vector<int> cost;
    int gas_cnt =0, cost_cnt = 0;
    
    for(int i = 0; i < gas_cnt; i++){
        cin>> gas[i];
    }

    for(int i = 0; i < cost_cnt; i++){
        cin>> cost[i];
    }

    cout<<circular_tour(gas, cost)<<endl;

    return 0;
}