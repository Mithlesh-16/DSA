#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Student{
        int scores[5];
        void input(int scores[5]);
        int calculateTotalScore(int scores);
        
};
int Student::calculateTotalScore(int scores){
    int total=0;
    total+=scores;
    return total;
    
}
void Student::input(int scores[5]){
    for(int i= 0;i<5;i++){
        cin>> scores[i];
        calculateTotalScore(scores[i]);       
    }
    
}
int main() {
    int n;
    cin>>n;
    Student s1;
    // cout<<total;
    for(int i =0; i<n-1;i++){
        Student s2;
        
    }
    
    
    
    
    return 0;
}
