#include <bits/stdc++.h>
void preciseFunc(double, int, int);
using namespace std;
int main()
{
    int n;
    cin >> n;

    // Sqrt using Binary Search
    
    int s = 0, e = n, beforeDecimal = -1;
    while (e >= s)
    {
        int mid = s + (e - s) / 2;
        if ((long long)mid * mid == n)
        {
            beforeDecimal = mid;
            break;
        }
        else if ((long long)mid * mid < n)
        {
            s = mid + 1;
            beforeDecimal = mid;
        }
        else
        {
            e = mid - 1;
        }
    }

    if ((long long)beforeDecimal * beforeDecimal != n)
    {
        preciseFunc(beforeDecimal, 3, n);
    }
    else
    {
        cout << beforeDecimal;
    }

    return 0;
}

// for More Precision

void preciseFunc(double beforeDecimal, int preciseUpto, int n)
{
    double preciseAns = beforeDecimal;
    for (int i = 1; i <= preciseUpto; i++)
    {
        double factor = 1 / pow(10, i);
        while ((preciseAns * preciseAns < n))
        {
            preciseAns += factor;
        }
        preciseAns -= factor;
    }
    cout << preciseAns;
}
