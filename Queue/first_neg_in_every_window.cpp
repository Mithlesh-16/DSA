#include <iostream>
#include <queue>
using namespace std;

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        
        vector<int> ans;
        
        queue<int> q;
        
        //for first k elements
        for(int i = 0 ; i < k; i++){
            if(arr[i] < 0) 
                q.push(i);
            
        }
        
        if(!q.empty())
            ans.push_back(arr[q.front()]);
        else
            ans.push_back(0);
        
        //for remaining elements
        for(int i = k; i < arr.size(); i++){
            
            //removal of elments from queue which are not in next kth group
            if(!q.empty() and i - q.front() >= k){
                q.pop();
            }
            
            //addition of new elements to queue
            if(arr[i] < 0){
                q.push(i);
            }
            
            if(!q.empty()){
                ans.push_back(arr[q.front()]);
            }else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};


int main() {


return 0;
}