#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &Books, int students, int mid)
{
    int studentsAlloted = 1, currentPages = 0;
    for (int i = 0; i < Books.size(); i++)
    {
        currentPages += Books[i];

        if (mid < Books[i]) return false;           // Too large to be handled by any single student;

        if (currentPages > mid)
        {
            studentsAlloted++;
            currentPages = Books[i];
        }
    }
    if(studentsAlloted != students) return false;
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
        }else{
            s = mid + 1;
        }
    }
    cout<<ans<<endl;
    return ans;
}


int main()
{
    int no_of_books = 0;
    cin>>no_of_books;
    vector<int> Books ;

    //Taking input
    for(int i = 0; i<no_of_books; i++){
        int tmp = 0;
        cin>> tmp;
        Books.push_back(tmp);
    } 
    int students = 0;
    cin >> students;
    int ans = bookAllocation(Books, students);
    cout << "The Minimum of Max Pages Alloted = " << ans << endl;

    return 0;
}