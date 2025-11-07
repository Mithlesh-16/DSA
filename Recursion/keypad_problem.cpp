#include <iostream>
#include <vector>
#include <string>
using namespace std;






// Given a string containing digits from 2-9 inclusive, 
// return all possible letter combinations that the number could represent. 
// Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. 
// Note that 1 does not map to any letters.


// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = "2"
// Output: ["a","b","c"]
 

// Constraints:

// 1 <= digits.length <= 4
// digits[i] is a digit in the range ['2', '9'].




class Solution {
private:
    void combine(vector<vector<string>>& alphabets, vector<string>& ans,
                 string digits, vector<int> index) {
        
        // base case
        for(int i = 0; i < index.size(); i++){
            if(index[i] >= alphabets[digits[i] - '0'].size()) return;
        }


        string temp;
        for(int i = 0; i<index.size(); i++){
            temp += alphabets[digits[i] - '0'][index[i]];
        }
        ans.push_back(temp);

        for(int i = 0; i < index.size(); i++){
            if(index[i]+1 < alphabets[digits[i] - '0'].size()) {
                index[i]++;
                combine(alphabets, ans, digits, index);
                index[i]--;
                
            }
        }

    }

public:
    vector<string> letterCombinations(string digits) {

        vector<vector<string>> alphabets;
        vector<string> ans;
        if(digits.size() == 0) return ans;

        alphabets.push_back({});
        alphabets.push_back({});
        alphabets.push_back({"a", "b", "c"});
        alphabets.push_back({"d", "e", "f"});
        alphabets.push_back({"g", "h", "i"});
        alphabets.push_back({"j", "k", "l"});
        alphabets.push_back({"m", "n", "o"});
        alphabets.push_back({"p", "q", "r", "s"});
        alphabets.push_back({"t", "u", "v"});
        alphabets.push_back({"w", "x", "y", "z"});


        vector<int> index(digits.size(), 0);

        combine(alphabets, ans, digits, index);
        
        return ans;
    }
};

int main() {


return 0;
}