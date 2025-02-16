#include<bits/stdc++.h>
using namespace std;
// void sorting(int*,int);
bool chkFound(int*,int,int);
int main(){
    int t,i=0;
    cin>>t;
    while(i<t){
        int n,k;
        cin>>n>>k;
        int brnd[k] ={-1},cost[k]={-1};

        for(int j=0;j<k;j++){
            cin>>brnd[j]>>cost[j];

        }

        
        int total[k] ={0},uptoBrnd[k] ={-1};
        for(int p=0;p<k;p++){
            total[p] =0;
            for(int q = p;q<k && !chkFound(uptoBrnd,p,brnd[p]);q++){
                // cout<<"q = "<<q<<endl;
                if(brnd[p] == brnd[q]){
                    total[p]+=cost[q];
                    // cout<<"total1 : "<<total[p]<<endl;
                }
            }
            uptoBrnd[p] = brnd[p];
        }


        
        //sorting total Cost
        int sizeTotal = sizeof(total)/sizeof(total[0]);
        sort(total, total + sizeTotal, greater<int>());

        int finalVal=0;

        int condn =0;
        if(n>k){
            condn = k;
        }else{
            condn = n;
        }

        for(int t2 =0;t2<condn;t2++){
            finalVal +=total[t2];
        }
        cout<<finalVal<<endl;
        
        i++;
    }

    return 0;
}

// void sorting(int *arr,int size){
//     for(int i = 0;i<size;i++){
//         for(int j = i+1;j<size;j++){
            
//             if(arr[j]>arr[i]){
//                 int temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] =temp;
//             }

//         }
//     }
// }
bool chkFound( int *arrFound,int size,int elem){
    for(int i=0;i<size;i++){
        if(arrFound[i]== elem){
            return 1;
        }
    }
    return 0;
}