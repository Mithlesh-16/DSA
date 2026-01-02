#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false;
        bool seenE = false;
        bool seenDot = false;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                seenDigit = true;
            } 
            else if (c == '+' || c == '-') {
                // Sign is valid only at start OR immediately after 'e'
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } 
            else if (c == '.') {
                // Dot valid only if no 'e' seen AND no dot seen
                if (seenDot || seenE) return false;
                seenDot = true;
            } 
            else if (c == 'e' || c == 'E') {
                // 'e' valid only if we have seen a digit AND no 'e' seen yet
                if (seenE || !seenDigit) return false;
                seenE = true;
                seenDigit = false; // CRITICAL: Reset because we need digits after 'e'
            } 
            else {
                return false; // Invalid character
            }
        }

        return seenDigit; // If we end with a digit seen (and not reset by trailing e), it's valid
    }
};