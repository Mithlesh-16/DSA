#include <bits/stdc++.h>
using namespace std;

//first of all, we start from the largest gap and then we reduce untill(gap >= 1)
//Then, gap = gap/2;

void shell_sort(vector<int> &arr, int n){


    //doing gapped insertion sort 
    for(int gap = n/2; gap >= 1; gap = gap/2){

        for(int i = gap; i < n; i++){
            int tmp = arr[i];
            int j = i;

            while(j >= gap and arr[j - gap] > tmp){
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = tmp;
        }
    }

    return ;
}

int main() {

    int n; 
    cin>>n;

    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin>> v[i];
    }

    shell_sort(v, n);

    for(int i = 0; i < n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

return 0;
}