#include <iostream>
using namespace std;

// merging two sorted arrays
void merge(int arr[], int start, int mid, int end)
{
    int size1 = mid - start + 1;
    int size2 = end - mid;
    int left[size1], right[size2];
    for (int i = 0; i < size1; i++)
    {
        left[i] = arr[start + i];
    }
    for (int i = 0; i < size2; i++)
    {
        right[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = start;
    for (; k <= end && j < size2 && i < size1; k++)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
    }
    if (j < size2)
    {
        for (; k <= end; k++)
        {
            arr[k] = right[j];
            j++;
        }
    }
    if (i < size1)
    {
        for (; k <= end; k++)
        {
            arr[k] = left[i];
            i++;
        }
    }
}

// divide and conquer
void divide(int arr[], int start, int end)
{
    if (start >= end)
        return;
    divide(arr, start, (start + end) / 2);
    divide(arr, (start + end) / 2 + 1, end);
    merge(arr, start, (start + end) / 2, end);
}

int main()
{

    int arr[5] = {2, 1, -1, 2, 0};
    divide(arr, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}