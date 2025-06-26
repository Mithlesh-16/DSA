#include <iostream>
#include <math.h>
long long power(int, int);
using namespace std;
int main()
{
    int n, str[32];
    cin >> n;
    unsigned long long ans = 0;
    int i = 0;
    while (n != 0)
    {
        int bit;
        bit = n & 1;
        ans = (bit * power(10, i)) + ans;
        n = n >> 1;
        i++;
    }
    cout << "Ans = " << ans << endl;

    return 0;
}
long long power(int base, int pow)
{
    if (pow == 0)
    {
        return 1;
    }
    else
    {
        return base * power(base, pow - 1);
    }
}