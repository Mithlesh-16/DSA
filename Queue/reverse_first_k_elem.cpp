#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        
        if(q.size() < k) return q;
        
        stack <int> s;
        
        for(int i = 0; i < k; i ++){
            s.push(q.front());
            q.pop();
        }
        
        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }
        
        int n = q.size() - k;
        
        while(n --){
            q.push(q.front());
            q.pop();
        }
        
        return q;
    }
};

int main() {


return 0;
}