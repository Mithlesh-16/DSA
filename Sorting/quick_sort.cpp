#include <iostream>
using namespace std;

int partition(int arr[], int start, int end)
{

    int pivot = arr[start];
    int count = start;

    /// moving the pivot
    for (int i = start; i <= end; i++)
    {
        if (arr[i] < pivot)
            count++;
    }
    swap(arr[start], arr[count]);

    // move the part of the array with elements less than the pivot to the left of the pivot
    int i = start, j = end;
    while (i < j)
    {
        if (arr[i] > pivot && arr[j] < pivot)
            swap(arr[i], arr[j]);
        if (arr[i] <= pivot)
            i++;
        if (arr[j] >= pivot)
            j--;
    }

    return count;
}

void quick_sort(int arr[], int start, int end)
{
    if (start >= end)
        return;

    int pivot = partition(arr, start, end);

    quick_sort(arr, start, pivot - 1);
    quick_sort(arr, pivot + 1, end);
}

int main()
{

    int arr[7] = {10, 2, 2, -1, 3, 21, 5};

    quick_sort(arr, 0, 6);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}