#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v; //capacity is memory allocated
    vector<int> a(5,1);   //all initialised to 1, By default initialised to 0;
    vector<int> last(a);

    //print Last
    cout<<"printing vector last after copying a : "<<endl;
    for(int i:last){
        cout<<i<<" ";
    }
    cout<<endl;
    
    cout<<"Size = "<<v.capacity()<<endl;
    v.push_back(1); //size is no of elements there
    cout<<"Size = "<<v.capacity()<<endl;

    v.push_back(1);
    cout<<"Size = "<<v.capacity()<<endl;
    v.push_back(1);
    cout<<"Size = "<<v.capacity()<<endl;
    v.push_back(1);
    cout<<"Size = "<<v.capacity()<<endl;
    v.push_back(1);
    cout<<"Size = "<<v.capacity()<<endl;

    cout<<"Element at 2nd Indx = "<<v.at(2)<<endl;
    cout<<"Front = "<<v.front()<<endl;
    cout<<"Back = "<<v.back()<<endl;

    cout<<"Before Pop : "<<endl;
    for(int i:v){           //befor Pop
        cout<<i<<"";
    }
    cout<<"\n";

    v.pop_back();

    cout<<"After Pop : "<<endl;
    for(int i:v){              //after pop
        cout<<i<<"";
    }
    cout<<endl;

    cout<<"Before Clear = "<<v.size()<<endl;
    v.clear();
    cout<<"After Clear = "<<v.size()<<endl;




    return 0;
}