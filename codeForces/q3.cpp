#include<bits/stdc++.h>
using namespace std;
int main(){

    int t,i=0;
    cin>>t;
    while(i<t){
        long long int n,m;
        cin>>n>>m;
        int a[n],b[m];

        for(int j =0;j<n;j++){
            cin>>a[j];
        }

        cin>>b[0];

        int flag =1,operation[n]={0};

        for(int j =0;j<n;j++){
            if(j==0){
                int condn = a[j] <= a[j+1];
                if(condn){
                    continue;
                }else{
                    a[j] = b[0] -a[j];
                    if(condn || b[0] -a[j+1] >=a[j]){
                        continue;
                    }else{
                        flag = 0;
                        break;
                    }
                }

            }else if(j == n-1){
                int condn = (a[j] >= a[j-1]);
                    if(condn){
                        continue;
                    }else{
                        a[j] = b[0] -a[j];
                        if(condn){
                            continue;
                        }else{
                            flag = 0;
                            break;
                        }
                    }

            }
            else{
                int condn =(a[j-1]<=a[j] && a[j]<=a[j+1]);
                if(condn){
                    continue;
                }else{
                    a[j] = b[0] -a[j];
                    if(condn){
                        continue;
                    }else{
                        if()

                        break;
                    }
                }
                
            }
        }


        if(flag){
            cout<<"yes";
        }else{
            cout<<"no";
        }


        i++;
    }

    return 0;
}