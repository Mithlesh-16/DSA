#include <iostream>
using namespace std;

void insertion_sort(int arr[], int end, int size)
{
    if (end == size)
        return;
    for (int i = end; i > 0; i--)
    {
        if (arr[i] < arr[i - 1])
            swap(arr[i - 1], arr[i]);
    }
    return insertion_sort(arr, end + 1, size);
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

    insertion_sort(arr, 1, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}