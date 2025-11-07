#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
template <typename T>
class Graph{

    public:
        unordered_map<T, list<T>> adj_list;

        void add_edge(T u, T v, bool direction){
            //direction = 0 -> undirected graph
            //direction = 1 -> directed graph

            //create an edge from u to v
            adj_list[u].push_back(v);

            if(!direction){
                // create an edge from v to u
                adj_list[v].push_back(u);
            } 
        }

    void print_adj_list(){
        for(auto &i : adj_list){
            cout<< i.first<<" -> ";
            for(auto &j: i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};

int main() {

    int n;
    cout<<"Enter the no. of nodes : "<<endl;
    cin>>n;

    int m;
    cout<<"Enter the no of edges : "<<endl;
    cin>>m;

    Graph<int> g;

    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;

        //creating an undirected graph
        g.add_edge(u, v, 0);
        
    }

    //printing the adjacency list
    g.print_adj_list();


    return 0;
}