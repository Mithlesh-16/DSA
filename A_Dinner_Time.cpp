#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{

    ll t;
    cin >> t;

    while (t--)
    {

        ll n, m, p, q;
        cin >> n >> m >> p >> q;

        if (n % p == 0 and q * (n / p) != m)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}