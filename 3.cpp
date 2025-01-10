#include <bits/stdc++.h>
// #include<iostream>
using namespace std;
int main(){
    int m1, n1, m2, n2;
    cin>> m1 >> n1 >> m2 >> n2;
    int mat1[m1][n1], mat2[m2][n2], mul[m1][n2];
    if(n1!=m2){
        cout<<"Matrix Multiplication Not possible!!"<<endl;
    }else{
        cout<< "1st Matrix :"<< endl;
        for(int i=0;i<m1;i++){
            for(int j=0;j<n1;j++){
                cin>>mat1[i][j];
                cout<<mat1[i][j]<<"\t";
            }
            cout<<endl;        
        }
        cout<< "2nd Matrix :"<< endl;
        for(int i=0;i<m2;i++){
            for(int j=0;j<n2;j++){
                cin>> mat2[i][j];
                cout<< mat2[i][j]<<"\t"; 
            }
            cout<<endl;
        }
        cout<< "Matrix after Multiplication :"<< endl;
        for(int i=0;i<m1;i++){
            for(int j=0;j<n2;j++){
                mul[i][j]=0;
                for(int k=0;k<n1;k++){
                    mul[i][j]= mat1[i][k] * mat2[k][j] + mul[i][j] ;
                }
                cout<< mul[i][j] <<"\t";

            }
            cout<<endl;
        }
    }
    return 0;
}