#include <iostream>
#include <string>
using namespace std;

int main()
{

    string sentence;
    getline(cin,sentence);

    for (int i = 0; i < sentence.size(); i++)
    {
        if (sentence[i] == ' ')
        {
            sentence.replace(i,1, "@40");
            i+=2;
        }
    }
    cout << sentence << endl;
    cout << sentence.size() << endl;

    return 0;
}