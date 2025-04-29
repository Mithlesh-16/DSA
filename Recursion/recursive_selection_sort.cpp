#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int size)
{
    if (size == 1 || size == 0)
    {

        return;
    }
    for (int i = 1; i < size; i++)
    {
        if (arr[0] > arr[i])
            swap(arr[0], arr[i]);
    }

    return selection_sort(arr+1, size - 1);
}

int main()
{

    cout<<"Selection Sort : "<<endl;
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    selection_sort(arr, n);

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}