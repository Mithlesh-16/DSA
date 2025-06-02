// binary search

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool is_possible(int stalls[], int no_of_stalls, int k, int mid){

    //using Greedy Approach because stalls arr is sorted
    int allotted_cows = 1;
    int last_position = stalls[0];
    for(int i = 1; i < no_of_stalls; i++){
        if(stalls[i] - last_position >= mid){
            allotted_cows++;
            last_position = stalls[i];
        }
        if(allotted_cows >= k) return true;
    }
    return false;
}

int aggressive_cows(int stalls[], int no_of_stalls, int k)
{
    sort(stalls, stalls + no_of_stalls);
    int e = stalls[no_of_stalls - 1] - stalls[0];

    //for s, find minimum difference
    int s = 1;
    int tmp = stalls[0];
    for(int i = 1; i<no_of_stalls; i++){
        if(stalls[i] - tmp < s) {
            s = stalls[i] - tmp;
            tmp = stalls[i];
        }
    }

    if (k > no_of_stalls)
        return -1;
    if (k == no_of_stalls)
        return s;

    int ans = -1;
    while(s <= e){
        int mid = s + (e - s)/2;
        if(is_possible(stalls, no_of_stalls, k, mid)){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    return ans;
}

int main()
{

    int no_of_stalls = 0;
    cin >> no_of_stalls;
    int stalls[no_of_stalls];
    for(int i = 0; i < no_of_stalls; i++){
        cin>>stalls[i];
    }
    int k = 0;
    cin >> k; // no of cows

    sort(stalls, stalls + no_of_stalls);
    cout << "Minimum of Maximum Distances : " << aggressive_cows(stalls, no_of_stalls, k) << endl;

    return 0;
}