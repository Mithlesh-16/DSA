#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        return ballsDistribution(position, m);
    }
    bool isPossible(vector<int>& position, int m, int mid) {
        int ball1 = position[0], count = 1;
        for (int j = 1; j < position.size(); j++) {
            if (position[j] - ball1 >= mid) {
                count++;
                ball1 = position[j];
            }
        }
        if (count == m)
            return true;
        else
            return false;
    }
    int ballsDistribution(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int mini = 0, ans = -1;
        long int maxi = *max_element(position.begin(), position.end()) -
                        *min_element(position.begin(), position.end());
        if (m > position.size())
            return ans;
        while (mini <= maxi) {
            long int mid = mini + (maxi - mini) / 2;
            if (isPossible(position, m, mid)) {
                mini = mid + 1;
                ans = mid;
            } else {
                maxi = mid - 1;
            }
        }
        return ans;
    }
};
int main(){
    cout<<"Done";
    return 0;
}