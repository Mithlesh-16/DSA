#include <bits/stdc++.h>
using namespace std;

//------------------Selection Sort------------------
void selection_sort(vector<int> &arr){
    for(int i = 0; i < arr.size(); i++){
        for(int j = i+1; j < arr.size(); j++){
            if(arr[i] > arr[j]) swap(arr[i], arr[j]);
        }
    }
    return;
}

//------------------Insertion Sort------------------
void insertion_sort(vector<int> &arr){
    for(int i = 1; i < arr.size(); i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    return;
}

//------------------Bubble Sort------------------
void bubble_sort(vector<int> &arr){
    for(int i = 0; i < arr.size(); i++){
        for(int j = 1; j < arr.size() - i; j++){
            if(arr[j] < arr[j - 1]){
                swap(arr[j], arr[j - 1]);
            }
        }
    }
    return;
}

//------------------Quick Sort------------------
int partitionIndex(vector<int> &arr, int start, int end){
    int pivot = arr[end];
    int i = start - 1;

    for(int j = start; j < end; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[end]);
    return (i+1);
}

void quick_sort(vector<int> &arr, int start, int end){
    if(start >= end) return;
    int p = partitionIndex(arr, start, end);
    quick_sort(arr, start, p - 1);
    quick_sort(arr, p + 1, end);
}

//------------------Merge Sort------------------
void merge(vector<int>& arr, int start, int end){
    int mid = (start + end) / 2;
    vector<int> left, right;

    for(int i = start; i <= mid; i++){
        left.push_back(arr[i]);
    }
    for(int j = mid + 1; j <= end; j++){
        right.push_back(arr[j]);
    }

    int i = 0, j = 0, index = start;

    while(i < left.size() && j < right.size()){
        if(left[i] < right[j]){
            arr[index++] = left[i++];
        }
        else{
            arr[index++] = right[j++];
        }
    }

    while(i < left.size()) arr[index++] = left[i++];
    while(j < right.size()) arr[index++] = right[j++];
}

void merge_sort(vector<int>& arr, int start, int end){
    if(start >= end) return;
    int mid = (start+end)/2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);

    merge(arr, start, end);
}

//------------------Bucket Sort------------------
void Bucket_sort(vector<int> &arr){
    int maxV = *max_element(arr.begin(), arr.end());
    vector<int> bucket(maxV + 1, 0);

    for(int x : arr) bucket[x]++;

    int idx = 0;
    for(int i = 0; i < bucket.size(); i++){
        while(bucket[i]--){
            arr[idx++] = i;
        }
    }
    return;
}

//------------------Heap Sort------------------
void heapify(vector<int> &arr, int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest]) largest = left;
    if(right < n && arr[right] > arr[largest]) largest = right;

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void Heap_sort(vector<int> &arr){
    int n = arr.size();

    for(int i = n/2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }

    for(int i = n - 1; i >= 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

//------------------Print Array------------------
void printArray(vector<int> arr){
    for(int x : arr) cout << x << " ";
    cout << endl;
}

//------------------MAIN FUNCTION (WITH SWITCH CASE)------------------
int main(){

    vector<int> arr;
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        arr.push_back(x);
    }

    cout << "\nWhich Sorting Algorithm?\n";
    cout << "1. Selection Sort\n";
    cout << "2. Insertion Sort\n";
    cout << "3. Bubble Sort\n";
    cout << "4. Quick Sort\n";
    cout << "5. Merge Sort\n";
    cout << "6. Bucket Sort\n";
    cout << "7. Heap Sort\n";
    cout << "Enter choice: ";

    int choice;
    cin >> choice;

    switch(choice){
        case 1: selection_sort(arr); break;
        case 2: insertion_sort(arr); break;
        case 3: bubble_sort(arr); break;
        case 4: quick_sort(arr, 0, arr.size()-1); break;
        case 5: merge_sort(arr, 0, arr.size()-1); break;
        case 6: Bucket_sort(arr); break;
        case 7: Heap_sort(arr); break;
        default: cout << "Invalid Choice!\n"; return 0;
    }

    cout << "\nSorted Array: ";
    printArray(arr);

    return 0;
}
