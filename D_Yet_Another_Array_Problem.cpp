#include <iostream>
#include <vector>

// We only need to check a small set of primes.
// The product of the first 16 primes is > 10^18,
// so at most 15 primes can divide all numbers in the array.
// The 16th prime (53) is guaranteed to work if the others fail.
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

/**
 * @brief Solves a single test case.
 */
void solve() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    long long answer = -1; // Default if no answer is found

    // Iterate through our list of primes
    for (int p : primes) {
        bool all_divisible = true;
        
        // Check if this prime 'p' divides all elements
        for (int i = 0; i < n; ++i) {
            if (a[i] % p != 0) {
                // We found an a[i] that is co-prime to p!
                all_divisible = false;
                break;
            }
        }
        
        // If 'p' did NOT divide all elements, then p is our
        // smallest z, because gcd(a[i], p) == 1 for at least one i.
        if (!all_divisible) {
            answer = p;
            break; // Found the smallest, so we can stop
        }
    }
    
    // According to the problem, a 'z' should always exist
    // within the range, so we'll always find one in our prime list.
    std::cout << answer << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve();
    }
    return 0;
}