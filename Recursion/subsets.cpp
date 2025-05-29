#include <iostream>
using namespace std;
#include <vector>

void subsets(vector<int> output, vector<vector<int>> &result, int index, int arr[], int size)
{
    if (index >= size)
    {
        result.push_back(output);
        return;
    }
    subsets(output, result, index + 1, arr, size);
    output.push_back(arr[index]);
    subsets(output, result, index + 1, arr, size);
}

int main()
{

    vector<int> output;
    vector<vector<int>> result;
    int n = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int size = sizeof(arr) / sizeof(arr[0]);
    subsets(output, result, 0, arr, size);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}