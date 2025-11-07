#include <bits/stdc++.h>
using namespace std;

void bin_sort(vector<int> &arr){
    int n = arr.size();
    int maxi = *max_element(arr.begin(), arr.end());
    
    vector<vector<int>> bins(n, vector<int>(n, -1));

    //searching for right bins to insert elements into
    for(int i = 0; i < n; i++){
        int index = arr[i]/maxi;
        if(index == n) index --;
        bins[index].push_back(arr[i]);
    }

    //sorting each value in each bins
    for(int i = 0; i < n; i++){
        sort(bins[i].begin(), bins[i].end());
    }

    //merging all the elements
    int index = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < bins[i].size(); j++){
            if(bins[i][j] != -1)
                arr[index++] = bins[i][j];
        }
    }

    return ;

}

int main() {

    int n;
    cin>>n;
    vector<int> v(n);

    //taking input
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    bin_sort(v);

    //printing the array
    for(int i = 0; i < n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;


return 0;
}