#include <bits/stdc++.h>
using namespace std;


// Allocate Minimum Pages

// Difficulty: Medium Accuracy: 35.51% Submissions: 353K+ Points: 4 Average Time: 35m
// Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

// Each student receives atleast one book.
// Each student is assigned a contiguous sequence of books.
// No book is assigned to more than one student.
// The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

// Note: If it is not possible to allocate books to all students, return -1.

// Examples:

// Input: arr[] = [12, 34, 67, 90], k = 2
// Output: 113
// Explanation: Allocation can be done in following ways:
// => [12] and [34, 67, 90] Maximum Pages = 191
// => [12, 34] and [67, 90] Maximum Pages = 157
// => [12, 34, 67] and [90] Maximum Pages = 113.
// The third combination has the minimum pages assigned to a student which is 113.
// Input: arr[] = [15, 17, 20], k = 5
// Output: -1
// Explanation: Since there are more students than total books, it's impossible to allocate a book to each student.
// Constraints:
// 1 ≤ arr.size() ≤ 106
// 1 ≤ arr[i], k ≤ 103

// Expected Complexities
// Time Complexity: O( n × log(sum(arr)))
// Auxiliary Space: O(1)


bool isPossible(vector<int> &Books, int students, int mid)
{
    int studentsAlloted = 1, currentPages = 0;
    for (int i = 0; i < Books.size(); i++)
    {
        currentPages += Books[i];

        if (mid < Books[i])
            return false; // Too large to be handled by any single student;

        if (currentPages > mid)
        {
            studentsAlloted++;
            currentPages = Books[i];
        }
    }
    if (studentsAlloted != students)
        return false;
    return true;
}

int bookAllocation(vector<int> Books, int students)
{
    int s = *max_element(Books.begin(), Books.end());
    int e = accumulate(Books.begin(), Books.end(), 0);
    if (students > Books.size())
        return -1;
    if (students == Books.size())
        return s;

    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (isPossible(Books, students, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    cout << ans << endl;
    return ans;
}

int main()
{
    int no_of_books = 0;
    cin >> no_of_books;
    vector<int> Books;

    // Taking input
    for (int i = 0; i < no_of_books; i++)
    {
        int tmp = 0;
        cin >> tmp;
        Books.push_back(tmp);
    }
    int students = 0;
    cin >> students;
    int ans = bookAllocation(Books, students);
    cout << "The Minimum of Max Pages Alloted = " << ans << endl;

    return 0;
}