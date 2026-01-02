#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        bool neg = false;
        long long ans = 0;

        //step 1 : trim the whitespace 
        while(s[i] == ' ') i++;

        //step 2 : check sign
        if(s[i] == '-'){
            i++;
            neg = true;
        } 
        else if(s[i] == '+'){
            i++;
        }
        
        // write no.
        while(i < s.size()){
            int dig = s[i] - '0';
            if(dig < 10 and dig >= 0){
                ans = ans * 10;
                if(ans > INT_MAX){
                    if(neg){
                        if(0 - ans > INT_MIN) return 0 - ans;
                        return INT_MIN;
                    }
                    return INT_MAX;
                }
                ans += dig;
            }else break;
            i++;
        }

        if(ans > INT_MAX){
            if(neg){
                if(0 - ans > INT_MIN) return 0 - ans;
                return INT_MIN;
            }
            return INT_MAX;
        }
        if(neg) return 0 - ans;

        return ans;

    }
};