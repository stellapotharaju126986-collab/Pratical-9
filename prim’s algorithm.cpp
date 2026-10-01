#include <iostream>
using namespace std;

#define V 5
#define INF 9999

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int parent[V];
    int key[V];
    bool visited[V];

    // Initialize values
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        visited[i] = false;
    }

    // Start from vertex 0
    key[0] = 0;
    parent[0] = -1;

    // Find MST
    for (int count = 0; count < V - 1; count++) {

        int min = INF;
        int u;

        // Find vertex with minimum key
        for (int v = 0; v < V; v++) {
            if (!visited[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        visited[u] = true;

        // Update adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[v] &&
                graph[u][v] < key[v]) {
                
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print MST
    int totalCost = 0;

    cout << "Edge \tWeight\n";

    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i
             << "\t" << graph[i][parent[i]] << endl;

        totalCost += graph[i][parent[i]];
    }

    cout << "Total cost = " << totalCost << endl;

    return 0;
}
