#include <iostream>
using namespace std;

int cnt_stairs(int strt, int end, int &cnt){
    if(strt == end){
        return 1;
    } 

    if(strt<end)
        return cnt_stairs(strt + 1, end, cnt) + cnt_stairs(strt + 2, end, cnt) ;
    else 
        return 0;
}

int main() {

    int strt = 0, end = 0, cnt = 0;
    cin>>strt>>end;
    
    cout<<cnt_stairs(strt, end, cnt);


return 0;
}