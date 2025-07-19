#include <iostream>
#include <string>
#include <vector>
using namespace std;

class soln{
    int score_recursion(string s){
        if (s.empty()) return 0;

        int score = 0;
        int bal = 0;
        int i = 0;

        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == '(') bal++;
            else bal--;

            // Found a complete balanced substring: s[i...j]
            if (bal == 0) {
                if (j - i == 1) {
                    // It is "()", score 1
                    score += 1;
                } else {
                    // It is "(...)", recursive call on inside part
                    score += 2 * score_recursion(s.substr(i + 1, j - i - 1));
                }
                i = j + 1; // Move to the next substring
            }
        }

        return score;
}
};

int main() {


return 0;
}