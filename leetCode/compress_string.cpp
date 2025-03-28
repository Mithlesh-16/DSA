#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Sir_Solution {
    public:
        // insert_s();
        int compress(vector<char>& chars) {
            int i =0,n = chars.size();
            int ans_index = 0;
            while(i<n){
                int j = i;
                while(j<n && chars[j] == chars[i]){
                    j++;
                }
    
                chars[ans_index++] = chars[i];
                int count = j - i;
                 
                string count_str = to_string(count);
                if(count>1){
                    for(char ch: count_str){
                        chars[ans_index++] = ch;
                    }
                }
                i = j;
            }
            return ans_index;
        }
    };

class My_Solution {
    public:
    //find_s func to find string s
        string find_s(int count,char base_char, string s){
            if (count == 1) {
                s += base_char;
            } else if (count < 10 && count > 0) {
                s += base_char+to_string(count);
            } else if (count >= 10) {
                string count_str = "";
                while (count > 0) {
                    count_str +=to_string( count % 10);
                    count = count / 10;
                }
                reverse(count_str.begin(), count_str.end());
                s += base_char + count_str;

            }
            return s;
        }

        int compress(vector<char>& chars) {
            string s = "";
            char base_char = chars[0];
            int count = 1;
            if(chars.size()==1){
                return chars.size();
            }
            for (int i = 1; i < chars.size(); i++) {
                if (chars[i] == base_char) {
                    count++;
                }
                else {
                    s = find_s(count,base_char,s);
                    base_char = chars[i];
                    count = 1;
                }
            }
            // cout<<"count = "<<count<<endl;
            // cout<<"base_char = "<<base_char<<endl;
            
            s = find_s(count,base_char,s);
            
            chars.insert(chars.begin(), s.begin(), s.end());
            chars.erase(chars.begin() + s.size(), chars.end());
            return chars.size();
        }
    };

int main() {


return 0;
}