#include <bits/stdc++.h>
using namespace std;
class Graph{
public:
    int V; 
    vector<vector<int>> adj;
    Graph(int n){
        V = n;
        adj.resize(V);
    }
    void addEdge(int u, int v){
        if(u >= V || v >= V || u < 0 || v < 0){
            cout << "Invalid vertices!" << endl;
            return;
        }
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected
        cout << "Edge added: " << u << " <-> " << v << endl;
    }
    void display(){
        cout << "\nGraph Adjacency List:\n";
        for(int i = 0; i < V; i++){
            cout << i << " -> ";
            for(int x : adj[i]) cout << x << " ";
            cout << endl;
        }
        cout << endl;
    }
    void BFS(int start){
        if(start >= V || start < 0){
            cout << "Invalid starting node!" << endl;
            return;
        }

        queue<int> q;
        vector<bool> visited(V, false);

        q.push(start);
        visited[start] = true;

        cout << "BFS Traversal: ";
        while(!q.empty()){
            int node = q.front();
            q.pop();

            cout << node << " ";

            for(int x : adj[node]){
                if(!visited[x]){
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
        cout << endl;
    }

    void DFSUtil(int node, vector<bool> &visited){
        visited[node] = true;
        cout << node << " ";
        for(int x : adj[node]){
            if(!visited[x]){
                DFSUtil(x, visited);
            }
        }
    }

    void DFS(int start){
        if(start >= V || start < 0){
            cout << "Invalid starting node!" << endl;
            return;
        }

        vector<bool> visited(V, false);
        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }
};

int main(){
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    Graph g(n);

    while(true){
        cout << "\n====== MENU ======\n";
        cout << "1. Add Edge\n";
        cout << "2. Display Graph\n";
        cout << "3. BFS Traversal\n";
        cout << "4. DFS Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        
        int choice;
        cin >> choice;

        switch(choice){
            case 1: {
                int u, v;
                cout << "Enter edge (u v): ";
                cin >> u >> v;
                g.addEdge(u, v);
                break;
            }
            case 2:
                g.display();
                break;

            case 3: {
                int start;
                cout << "Enter start node: ";
                cin >> start;
                g.BFS(start);
                break;
            }

            case 4: {
                int start;
                cout << "Enter start node: ";
                cin >> start;
                g.DFS(start);
                break;
            }

            case 5:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
