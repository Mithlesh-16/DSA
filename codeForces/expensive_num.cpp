#include <iostream>
using namespace std;

int main() {

    int t;
    cin>>t;
    while(t--){

        string nums = "";
        cin>>nums;
        
        int idx = nums.size() - 1;

        while(idx>= 1){
            if(nums[idx] != '0')
                break;
            idx--;
        }
        int cnt = 0;
        for(int i = 1; i<idx; i++){
            if (nums[i] == '0') cnt++;
        }

        cout<<nums.size() - ++cnt<<endl;

                

    }

return 0;
}