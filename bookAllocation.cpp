#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int>, int, int, int *, int *);
int bookAllocation(vector<int>, int);
int main()
{
    vector<int> Books = {12, 34, 67, 90};
    // vector<int> Books={5,17,100,11};
    // vector<int> Books={}; 
    int students = 0;
    cin >> students;
    int ans = bookAllocation(Books, students);
    cout << "The Minimum of Max Pages Alloted = " << ans << endl;

    return 0;
}

bool isPossible(vector<int> Books, int students, int mid, int *s, int *e)
{
    int studentsAlloted = 1, currentPages = 0;
    for (int i = 0; i < Books.size(); i++)
    {
        currentPages += Books[i];
        if (currentPages > mid && mid >= Books[i])
        {
            studentsAlloted++;
            currentPages = Books[i];
        }
        else if (mid < Books[i])
        {
            *s = mid + 1;
            return 0;
        }
    }
    if (studentsAlloted > students)
    {
        *s = mid + 1;
        return 0;
    }
    else if (studentsAlloted < students)
    {
        *e = mid - 1;
        return 0;
    }
    return 1;
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
        int *S = &s, *E = &e;
        if (isPossible(Books, students, mid, S, E))
        {
            ans = mid;
            e = mid - 1;
        }
    }
    return ans;
}