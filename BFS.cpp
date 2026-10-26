
#include <iostream>
#include <vector>
#include <queue>
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

    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";

        while (!q.empty()) {
            int vertex = q.front();
            q.pop();

            cout << vertex << " ";

            for (int neighbor : adj[vertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        cout << endl;
    }
};

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    if (V <= 0) {
        cout << "Number of vertices must be positive." << endl;
        return 1;
    }

    Graph g(V);

    cout << "Enter number of edges: ";
    cin >> E;

    if (E < 0) {
        cout << "Number of edges cannot be negative." << endl;
        return 1;
    }

    cout << "Enter edges (u v):" << endl;

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        if (u < 0 || u >= V || v < 0 || v >= V) {
            cout << "Invalid vertex!" << endl;
            return 1;
        }

        g.addEdge(u, v);
    }

    int start;

    cout << "Enter starting vertex (0 to " << V - 1 << "): ";
    cin >> start;

    if (start < 0 || start >= V) {
        cout << "Invalid starting vertex!" << endl;
        return 1;
    }

    g.BFS(start);

    return 0;
}
