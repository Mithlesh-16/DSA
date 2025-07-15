#include <iostream>
using namespace std;

#include <bits/stdc++.h>

// void cost_cnt(stack<char>& s, int& cost){
//   //base case
//   if(s.empty()){
//     return;
//   }

//   char tmp = s.top();
//   s.pop();

//   cost_cnt(s, cost);

//   //backtracking
//   if(!s.empty() and ((s.top() == '}' and tmp == '{') or (s.top() == '{' and tmp == '}')) ){
//     cost+=2;
//     s.pop(); 
//   }
//   else if(!s.empty() and 
//         ((s.top() == '{' and tmp == '{') or (s.top() == '}' and tmp == '}'))){
//     s.pop();
//     cost++;
//   }
//   else{
//     s.push(tmp);
//   }
// } 


int findMinimumCost(string str) {
  if(str.size() %2 != 0) return -1;

  int i = 0, cost = 0;
  stack<char> s;
  while(i < str.size()){
    if(str[i] == '{')
      s.push(str[i]);
    else {
      if(!s.empty() and s.top() == '{')
        s.pop();
      else{
        s.push(str[i]);
      }
    }

    i++;
  }
  if(s.empty())return cost;

  int close = 0, open = 0;
  while(!s.empty()){
    if(s.top() == '{') open++;
    else close++;
    s.pop();
  }


  return ((open + 1)/2) + (close + 1)/2;

}
int main()
{

    return 0;
}