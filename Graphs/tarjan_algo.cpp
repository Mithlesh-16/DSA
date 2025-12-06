#include <bits/stdc++.h>
using namespace std;

class TarjanSCC {
public:
    int timer = 0;  
    vector<int> disc, low;  //discovery time and low -> lowest possible time 
    vector<bool> inStack;   //to track the active nodes in the current dfs path
    stack<int> st;          
    vector<vector<int>> adj; 
    vector<vector<int>> sccs;   //ans

    TarjanSCC(int n) {
        disc.assign(n, -1);
        low.assign(n, -1);
        inStack.assign(n, false);
        adj.resize(n);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void dfs(int u) {
        disc[u] = low[u] = timer++;
        st.push(u);
        inStack[u] = true;

        for (int v : adj[u]) {
            if (disc[v] == -1) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
            else if (inStack[v]) {
                low[u] = min(low[u], disc[v]);
            }
        }

        // If u is the root of a SCC
        if (low[u] == disc[u]) {
            vector<int> comp;

            while (true) {
                int v = st.top();
                st.pop();
                inStack[v] = false;
                comp.push_back(v);

                if (v == u) break;
            }

            sccs.push_back(comp);
        }
    }

    vector<vector<int>> getSCCs(int n) {
        for (int i = 0; i < n; i++) {
            if (disc[i] == -1) dfs(i);
        }
        return sccs;
    }
};

int main() {

    // ---------- TESTCASE ----------
    int n = 5;
    TarjanSCC g(n);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    vector<vector<int>> res = g.getSCCs(n);

    int idx = 1;
    for (auto &comp : res) {
        cout << "SCC " << idx++ << ": ";
        for (int node : comp) cout << node << " ";
        cout << "\n";
    }

    return 0;
}
