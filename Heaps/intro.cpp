#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class heap{
    public:
        int size = 0;
        int arr[100];
        int index = 0;

        heap(){
            arr[0] = -1;
            index = 1;
        }

        //insert at the last
        // O(logN) - time Complexity
        void insert(int val){
            size = size + 1;
            arr[index++] = val;
            int newIndex = index - 1;
            while(newIndex/2 > 0){
                int parent = newIndex/2;
                if(arr[parent] < arr[newIndex]){
                    swap(arr[parent], arr[newIndex]);
                    newIndex = parent;
                }
                else return ;
            }
        }

        //deleting root node from heap
        // O(logN) = time complexity

        void deleteFromHeap(){
            if(size == 0) return;
            
            arr[1] = arr[size--];
            int newIndex = 1;
            while(newIndex <= size){
                int leftIndex = 2*newIndex;
                int rightIndex = leftIndex + 1;
                int largest = newIndex;

                if(leftIndex <= size and arr[leftIndex] > arr[largest]){
                    largest = leftIndex;
                }
                if(rightIndex <= size and arr[rightIndex] > arr[largest]){
                    largest = rightIndex;
                }

                if(largest != newIndex){
                    swap(arr[largest], arr[newIndex]);
                    newIndex = largest;
                }else break;
            }
        }


        //making heap from given array
        void makeHeap(){
            for(int i = 1; i <= size/2; i++){
                heapify(i);
            }
        }

        void heapify(int i){
            int newIndex = i;
            while(newIndex <= size/2){
                int largest = newIndex;
                int leftIndex = 2*newIndex;
                int rightIndex = 2*newIndex + 1;

                if(leftIndex <= size and arr[largest] < arr[leftIndex]){
                    largest = leftIndex;
                }
                if(rightIndex <= size and arr[largest] < arr[rightIndex]){
                    largest = rightIndex;
                }

                if(largest != newIndex){
                    swap(arr[largest], arr[newIndex]);
                    newIndex = largest;
                }else return;
            }
        }

        //print Heap
        void print(){
            for(int i = 1; i <= size; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

int main() {

    heap h1;
    h1.insert(20);
    h1.insert(37);
    h1.insert(40);
    h1.insert(23);
    h1.insert(55);
    h1.insert(69);
    h1.insert(13);
    h1.insert(5);
    h1.print();
    h1.deleteFromHeap();
    h1.print();
    h1.deleteFromHeap();
    h1.print();

return 0;
}