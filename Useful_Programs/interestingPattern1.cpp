#include <iostream>
using namespace std;
int main()
{
    int n, Num, noOfCols, newNum, midCols, lastNum;
    cin >> n;
    noOfCols = n * 2 - 1;
    newNum = n - 1;
    midCols = noOfCols - 2;
    int secMidCols = 1;
    for (int i = 1; i <= noOfCols; i++)
    {
        cout << n;
    }
    cout << endl;
    // First Half Section
    for (int i = 1; i <= noOfCols / 2; i++)
    { // First Triangular Part
        Num = n;
        for (int j = 1; j <= i; j++)
        {
            cout << Num;
            Num--;
        }
        // second Inverted Triangular part
        for (int j = 1; j <= midCols; j++)
        {
            cout << newNum;
        }

        // last Triangular part
        lastNum = newNum + 1;
        for (int j = 1; j <= i; j++)
        {
            cout << lastNum;
            lastNum++;
        }
        midCols -= 2;
        newNum--;
        cout << endl;
    }
    // second half Section

    int secNum;
    for (int i = noOfCols / 2; i >= 1; i--)
    {
        secNum = n;
        for (int j = 1; j <= i; j++)
        {
            cout << secNum;
            secNum--;
        }

        int no = secNum + 1;
        for (int j = 1; j <= secMidCols; j++)
        {
            cout << no;
        }
        secMidCols += 2;

        for (int j = 1; j <= i; j++)
        {
            cout << no;
            no++;
        }
        cout << endl;
    }
    return 0;
}
