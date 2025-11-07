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
            if(!q.empty() && ( q.front() <= i - k)){
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

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        
        //find negative in first k size window
        
        deque <int> neg;
        vector<int> ans;
        
        for(int i = 0; i < k and i < arr.size(); i++){
            
            if(arr[i] < 0){
                neg.push_back(i);
            }
            
        }
        
        if(neg.empty())
            ans.push_back(0);
        else ans.push_back(arr[neg.front()]);
        
        //for remaining elements
        for(int i = k; i < arr.size(); i++){
            
            if(!neg.empty() && neg.front() <= i - k){
                neg.pop_front();
            }
            
            if(arr[i] < 0){
                neg.push_back(i);
            }
            
            if(neg.empty()) ans.push_back(0);
            else ans.push_back(arr[neg.front()]);
            
        }
        
        return ans;
    }
};

int main() {


return 0;
}