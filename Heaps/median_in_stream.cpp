#include <bits/stdc++.h>
using namespace std;







//very important q in heap
// 295. Find Median from Data Stream

// The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

// For example, for arr = [2,3,4], the median is 3.
// For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
// Implement the MedianFinder class:

// MedianFinder() initializes the MedianFinder object.
// void addNum(int num) adds the integer num from the data stream to the data structure.
// double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

// Example 1:

// Input
// ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
// [[], [1], [2], [], [3], []]
// Output
// [null, null, null, 1.5, null, 2.0]

// Explanation
// MedianFinder medianFinder = new MedianFinder();
// medianFinder.addNum(1);    // arr = [1]
// medianFinder.addNum(2);    // arr = [1, 2]
// medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
// medianFinder.addNum(3);    // arr[1, 2, 3]
// medianFinder.findMedian(); // return 2.0









class MedianFinder {
    priority_queue<double, vector<double>> maxHeap;
    priority_queue<double, vector<double>, greater<int>> minHeap;
    double median = -1;

public:
    MedianFinder() {
        
    }
    
    int signum(int a, int b){
        if(a > b) return 1;
        if(a < b) return -1;
        return 0;
    }
    void addNum(int num) {
        switch(signum(maxHeap.size(), minHeap.size())){
            case 0:
                if(num < median){
                    maxHeap.push(num);
                    median = maxHeap.top();
                }
                else{
                    minHeap.push(num);
                    median = minHeap.top();
                }
                break;
            
            case 1:
                if(num < median){
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(num);
                    median = (maxHeap.top() + minHeap.top()) /2;
                }
                else{
                    minHeap.push(num);
                    median = (maxHeap.top() + minHeap.top()) /2;
                }
                break;

            case -1:
                if(num < median){
                    maxHeap.push(num);
                    median = (maxHeap.top() + minHeap.top()) /2;
                }
                else{
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(num);
                    median = (maxHeap.top() + minHeap.top()) /2;
                }
        }
    }
    
    
    double findMedian() {
        
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {


return 0;
}