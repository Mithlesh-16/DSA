#include <iostream>
using namespace std;

int main() {

int a = 10;
int *p = &a;
int **q = &p;
int b = 20;
*q = &b;
cout<<q<< " "<<&b<<""<<endl;
(*p)++;
cout << a << " " << b << endl;


return 0;
}