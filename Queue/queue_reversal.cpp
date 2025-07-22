#include <iostream>
#include <queue>
using namespace std;


class reverse {
  private:
    void soln(queue<int> &q){
        //base case
        if(q.empty()){
            return ;
        }
        
        int front = q.front();
        q.pop();
        soln(q);
        q.push(front);
    }
    
  public:
    queue<int> reverseQueue(queue<int> &q) {
        
        soln(q);
        
        return q;
        
    }
};


int main() {



    return 0;
}