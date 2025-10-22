#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t = 0;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;

        if (k == pow(n, 2) - 1)
        {
            cout << "NO" << endl;
        }
        else
        {

            vector<vector<char>> grid(n, vector<char> (n, ' '));

            cout << "YES" << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (k){
                        grid[i][j] = 'L';
                        k--;
                    }

                    else if (grid[i][j] == ' ')
                    {
                        if (j + 1 < n and grid[i][j + 1] == ' ')
                        {
                            grid[i][j] = 'R';
                            grid[i][j + 1] = 'L';
                        }
                        else if (j + 1 < n and grid[i][j + 1] != ' ')
                        {
                            grid[i][j] = 'R';
                        }
                        else
                        {
                            if (i + 1 < n)
                            {
                                grid[i][j] = 'D';
                                grid[i + 1][j] = 'U';
                            }
                            else
                            {
                                if (j - 1 >= 0 and j - 2 >= 0)
                                {
                                    if (grid[i][j - 1] == 'L' and grid[i][j - 2] == 'R')
                                    {
                                        grid[i][j] = 'L';
                                    }
                                    else
                                    {
                                        grid[i][j] = 'U';
                                    }
                                }
                            }
                        }
                    }
                    cout<<grid[i][j];
                }
                cout<<endl;
            }

        }
    }

    return 0;
}