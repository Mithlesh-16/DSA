#include <iostream>
#include <vector>
using namespace std;
int binarySearch(vector<int>, int);
int main()
{
    vector<int> elemArr(8);
    elemArr = {1, 3, 4, 10, 12, 15, 22, 31}; // Binary search works only on sorted array
    vector<int> elemArr1(7);
    elemArr1 = {2, 3, 5, 9, 13, 19, 21};
    int target;
    cin >> target;
    int check = binarySearch(elemArr, target);
    cout << "IN Array 1 ,element " << target << " at Index " << check << endl;
    check = binarySearch(elemArr1, target);
    cout << "IN Array 2 ,element " << target << " at Index " << check << endl;
    return 0;
}
int binarySearch(vector<int> arr, int target)
{
    int size = arr.size(), start = 0, end = size - 1, mid = (start + end) / 2;
    while (start <= end)
    {
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }
    return -1;
}