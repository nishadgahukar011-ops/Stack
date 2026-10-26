
#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    void DFS(int start, vector<bool>& visited) {
        visited[start] = true;
        cout << start << " ";

        for (int neighbor : adj[start]) {
            if (!visited[neighbor]) {
                DFS(neighbor, visited);
            }
        }
    }

    void traverseDFS(int start) {
        vector<bool> visited(V, false);
        cout << "DFS Traversal: ";
        DFS(start, visited);
        cout << endl;
    }
};

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    Graph g(V);

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int start;
    cout << "Enter starting vertex (0 to " << V - 1 << "): ";
    cin >> start;

    if (start < 0 || start >= V) {
        cout << "Invalid starting vertex!" << endl;
        return 1;
    }

    g.traverseDFS(start);

    return 0;
}
