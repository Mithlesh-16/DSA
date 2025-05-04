#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += (1LL << i); // 2^i using bit shift
    }

    cout << ans << endl;
    return 0;
}
