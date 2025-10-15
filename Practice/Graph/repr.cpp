#include <bits/stdc++.h>
using namespace std;

class graph {

public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool dirn) {
        // dirn = 0 - undirected

        adj[u].push_back(v);
        if (dirn == 0)
            adj[v].push_back(u);
    }

    void print() {
        for (auto i : adj) {
            cout << i.first << "-> ";
            for (auto j:adj)
                cout << j << ", ";
            cout << endl;
        }
    }
};

int main() {
    int n, m;

    cout << "Enter no. of nodes: " << endl;
    cin >> n;

    cout << "Enter no. of edges: " << endl;
    cin >> m;

    graph g;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // creating an undirected graph
        g.addEdge(u, v, 0);
    }
    g.print();
    return 0;
}