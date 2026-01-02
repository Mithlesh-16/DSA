#include <iostream>
using namespace std;

class Animal{
    public:
        virtual void speak(){
            cout<<"Animal Speaks !!"<<endl;
        }
        virtual string poisonous () = 0;

    };

class Dog : public Animal{
    void speak(){
        cout<<"Dog Barks !!"<<endl;
    }
    string poisonous() override{
        cout<<"not poisonous at all !!"<<endl;
    }
};

int main() {

    Dog d;
    Animal *a = &d;
    a->speak();

return 0;
}