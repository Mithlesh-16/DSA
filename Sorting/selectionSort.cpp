#include <bits/stdc++.h>
using namespace std;
// int minOfArr(int arr[5],int round){
//     int min = arr[round-1];
//     // cout<<"min :"<<min<<endl;
//     for(int i = round;i<5;i++){
//         if (arr[i] < min){
//             int temp = min;
//             min = arr[i];
//             arr[i] = temp;
//         }
//     }
//     // cout<<"min :"<<min<<endl;

//     return min;
// }

/*
Use Case:
 When array/vector Size is small
*/

int main()
{
    auto start = chrono::high_resolution_clock::now(); // Start time

    int arr[10] = {2, 7, 9, 7, 56, 45, 9, 2, 7, 1};

    // for(int i =0;i<10;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<"\n";

    for (int i = 0; i < 9; i++)    //size = 10
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n";
    auto stop = chrono::high_resolution_clock::now(); // End time
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Program executed in: " << duration.count() << " microseconds" << endl;

    return 0;
}
