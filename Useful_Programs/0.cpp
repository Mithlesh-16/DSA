#include <bits/stdc++.h>
using namespace std;

int main()
{

    // file handling
    fstream iofile("0.txt", ios::in | ios::out| ios::app);
    string s;

    if (!iofile.is_open())
    {
        cerr << "error opening file" << endl;
    }

    getline(cin, s);
    iofile << s << endl;
    iofile.close();

    return 0;
}