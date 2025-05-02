// #include <bits/stdc++.h>
// using namespace std;

// int partition(int arr[], int s, int e){

//     //count smaller numbers
//     int pivot = arr[s];
//     int cnt = s;
//     for(int i = s+1; i <= e; i++){
//         if(arr[i] <= pivot) cnt++;
//     }
//     swap(arr[s], arr[cnt]);

    
//     //two pointer approach
//     int i = s, j = e;
//     while(i<=j){
//         if(arr[i]>pivot && arr[j]<=pivot) {
//             swap(arr[i], arr[j]);
//             i++;
//             j--;
//         }
//         else if(arr[i] <= pivot && arr[j] > pivot){
//             i++;
//             j--;
//         }
//         else if(arr[i]<= pivot){
//             i++;
//         }
//         else if(arr[j] > pivot){
//             j--;
//         }
    
//     }
//     return cnt;

// }

// void quick_sort(int arr[], int s, int e){
//     //base case
//     if(s>=e){
//         return;
//     }

//     //partition index 
//     int p = partition(arr, s, e);

//     //left part sort kare
//     quick_sort(arr, s, p-1);

//     //right part sort kare
//     quick_sort(arr, p+1, e);

// }

// int main() {

//     int n;
//     cin>>n;
//     int arr[n];

//     for(int i = 0; i < n; i++){
//         cin>>arr[i];
//     }
    
//     quick_sort(arr, 0, n-1);

//     for(int i = 0; i < n; i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;


// return 0;
// }


#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

// ---------- Your Quick Sort ----------
int partition_custom(int arr[], int s, int e) {
    int pivot = arr[s];
    int cnt = s;
    for (int i = s + 1; i <= e; i++) {
        if (arr[i] <= pivot) cnt++;
    }
    swap(arr[s], arr[cnt]);

    int i = s, j = e;
    while (i < j) {
        if (arr[i] > pivot && arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        } else if (arr[i] <= pivot && arr[j] > pivot) {
            i++;
            j--;
        } else if (arr[i] <= pivot) {
            i++;
        } else if (arr[j] > pivot) {
            j--;
        }
    }
    return cnt;
}

void quick_sort_custom(int arr[], int s, int e) {
    if (s >= e) return;
    int p = partition_custom(arr, s, e);
    quick_sort_custom(arr, s, p - 1);
    quick_sort_custom(arr, p + 1, e);
}

// ---------- Lomuto Quick Sort ----------
int partition_lomuto(int arr[], int s, int e) {
    int pivot = arr[e];
    int i = s - 1;
    for (int j = s; j < e; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[e]);
    return i + 1;
}

void quick_sort_lomuto(int arr[], int s, int e) {
    if (s >= e) return;
    int p = partition_lomuto(arr, s, e);
    quick_sort_lomuto(arr, s, p - 1);
    quick_sort_lomuto(arr, p + 1, e);
}

// ---------- Main Function ----------
int main() {
    int n = 100000;
    vector<int> original(n);
    srand(time(0));
    for (int i = 0; i < n; i++) {
        original[i] = rand();
    }

    vector<int> a = original;
    vector<int> b = original;

    // Test your Quick Sort
    auto start = high_resolution_clock::now();
    quick_sort_custom(a.data(), 0, n - 1);
    auto stop = high_resolution_clock::now();
    auto duration_custom = duration_cast<milliseconds>(stop - start).count();
    cout << "Custom Quick Sort Time: " << duration_custom << " ms" << endl;

    // Test Lomuto Quick Sort
    start = high_resolution_clock::now();
    quick_sort_lomuto(b.data(), 0, n - 1);
    stop = high_resolution_clock::now();
    auto duration_lomuto = duration_cast<milliseconds>(stop - start).count();
    cout << "Lomuto Quick Sort Time: " << duration_lomuto << " ms" << endl;

    // Compare outputs
    if (a == b)
        cout << "✅ Both arrays are sorted identically.\n";
    else
        cout << "❌ Mismatch in sorted arrays!\n";

    return 0;
}
