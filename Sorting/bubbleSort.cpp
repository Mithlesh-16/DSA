#include <bits/stdc++.h>
#include <chrono>
using namespace std;
int main()
{
    auto start = chrono::high_resolution_clock::now(); // Start time

    int arr[10] = {4, 2, 1, 4, 5, 7, 5, 3, 2, 1};
    for (int h = 0; h < 9; h++) // size = 10
    {
        for (int i = 0; i < 9 - h; i++)
        {
            if (arr[i + 1] < arr[i])
            {
                swap(arr[i + 1], arr[i]);
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    // find time taken
    cout << "\n";
    auto stop = chrono::high_resolution_clock::now(); // End time
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << "Program executed in: " << duration.count() << " milliseconds" << endl;

    return 0;
}