#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int size)
{
    if (size == 1 || size == 0)
    {

        return;
    }
    for (int i = 1; i < size; i++)
    {
        if (arr[i - 1] > arr[i])
            swap(arr[i - 1], arr[i]);
    }

    return bubble_sort(arr, size - 1);
}

int main()
{

    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bubble_sort(arr, n);

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}