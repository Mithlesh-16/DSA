#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort

/**
 * @brief Solves a single test case for the broken wand problem.
 */
void solve() {
    int n;
    std::cin >> n;
    
    std::vector<long long> a(n);
    bool has_odd = false;
    bool has_even = false;
    
    // Read the array and check for parities
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (a[i] % 2 == 0) {
            has_even = true;
        } else {
            has_odd = true;
        }
    }
    
    // If both parities exist, we can swap any two elements.
    // To get the lexicographically smallest arrangement, we sort the array.
    if (has_odd && has_even) {
        std::sort(a.begin(), a.end());
    }
    
    // If only one parity exists (all odd or all even), no swaps are possible.
    // In this case, we just print the original array (which is still in 'a').
    // If we did sort, we print the sorted version.
    
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << "\n";
}

int main() {
    // Optimize C++ input/output operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }
    return 0;
}