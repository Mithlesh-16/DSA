#include <bits/stdc++.h>
using namespace std;

void quick_sort(vector<int> &nums, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int i = start - 1, j = start;
    int pivot = end;

    while (j < pivot)
    {
        if (nums[j] <= nums[pivot])
        {
            i++;
            swap(nums[i], nums[j]);
        }
        j++;
    }
    i++;
    swap(nums[pivot], nums[i]);
    pivot = i;


    quick_sort(nums, start, pivot - 1);
    quick_sort(nums, pivot + 1, end);
}

int main()
{
    vector<int> nums = {1, 3, 2, 4, 34, 32, 23, 34, 0, 32};
    quick_sort(nums, 0, nums.size() - 1);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}