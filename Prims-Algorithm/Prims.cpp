#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, weight;

    // Overloading < operator for sorting in priority queue
    bool operator<(const Edge& other) const {
        return weight > other.weight;
    }
};

// Function to find the minimum spanning tree using Prim's algorithm
vector<Edge> primMST(const vector<vector<pair<int, int>>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<Edge> mst;

    // Priority queue to select the minimum weight edge
    priority_queue<Edge> pq;

    // Start with vertex 0
    visited[0] = true;
    for (const auto& neighbor : graph[0]) {
        pq.push({0, neighbor.first, neighbor.second});
    }

    while (!pq.empty()) {
        Edge current = pq.top();
        pq.pop();

        if (visited[current.v]) {
            continue;
        }

        visited[current.v] = true;
        mst.push_back(current);

        // Explore neighbors of the current vertex
        for (const auto& neighbor : graph[current.v]) {
            if (!visited[neighbor.first]) {
                pq.push({current.v, neighbor.first, neighbor.second});
            }
        }
    }

    return mst;
}

int main() {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<pair<int, int>>> graph(n);

    cout << "Enter edge details (u v w) for each edge:\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    // Find the Minimum Spanning Tree
    vector<Edge> result = primMST(graph);

    // Output the Minimum Spanning Tree
    cout << "\nEdges of the Minimum Spanning Tree (Prim's Algorithm):\n";
    int totalCost = 0;
    for (const Edge& edge : result) {
        totalCost += edge.weight;
        cout << edge.u << " - " << edge.v << " : " << edge.weight << "\n";
    }
    cout << "Total cost of the Minimum Spanning Tree: " << totalCost << "\n";

    return 0;
}
