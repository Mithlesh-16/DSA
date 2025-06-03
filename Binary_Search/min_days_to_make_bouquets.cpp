#include <bits/stdc++.h>
using namespace std;
class Solution {
    bool is_possible(vector<int>& bloomDay, int m, int k, int mid) {
        int flowers_for_bouquets = 1, flowers_bloomed = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            flowers_bloomed += bloomDay[i];

            if (flowers_bloomed > mid && bloomDay[i] <= mid) {
                flowers_for_bouquets++;
                flowers_bloomed = bloomDay[i];
            }

            if(bloomDay[i] > mid) flowers_bloomed = 0;

            if (flowers_for_bouquets == k){
                flowers_for_bouquets = 0;
                m--;
            }
        }
        return m <= 0;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int s = *min_element(bloomDay.begin(), bloomDay.end());
        int e = *max_element(bloomDay.begin(), bloomDay.end());

        if (m * k > bloomDay.size())
            return -1;

        int ans = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (is_possible(bloomDay, m, k, mid)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};

int main() {


return 0;
}