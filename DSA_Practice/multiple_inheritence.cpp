#include <iostream>
using namespace std;

class overloading{

    public:
        int x;
    overloading(){
        cin>>x;
        this->x = x;
    }
    int operator+(const overloading &o){
        return this->x + o.x;
    }

};

int main() {

    overloading o1;
    overloading o2;

    cout<<o1+o2;
    

return 0;
}
