#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{

    ll t;
    cin >> t;

    while (t--)
    {

        ll n;
        cin >> n;
        vector<vector<int>> v(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> v[i][j];
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(v[i][j] < 0){
                int side = min(n - i - 1, n - j - 1);
                    int cnt_inc = abs(v[i][j]);
                    int tmp = 0;
                    while (tmp <= side)
                    {
                        v[i + tmp][j + tmp] += cnt_inc;
                        tmp++;
                    }
                    cnt+= cnt_inc;
                }
            }
        }

        cout << cnt << endl;
    }

    return 0;
}