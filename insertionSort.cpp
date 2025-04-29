#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {10, 1, 7, 4, -1, 2, 11};
    for (int i = 1; i < 7; i++)
    {
        int temp = arr[i];
        
        for (int j = i-1; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[i] = temp;
    }

    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}