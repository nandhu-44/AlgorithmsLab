#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge
{
    int u, v, weight;
};

class DisjointSet
{
private:
    vector<int> parent, rank;

public:
    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int findSet(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = findSet(parent[v]);
    }

    void unionSets(int a, int b)
    {
        a = findSet(a);
        b = findSet(b);
        if (a != b)
        {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
};

vector<Edge> kruskalMST(vector<Edge> &edges, int n)
{
    vector<Edge> result;

    // Step 1: Create disjoint sets for each vertex
    DisjointSet ds(n);

    // Step 2: Sort the edges in non-decreasing order of weight
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b)
         { return a.weight < b.weight; });

    // Step 3: Iterate through sorted edges and add to MST if they don't form a cycle
    for (const Edge &edge : edges)
    {
        int u = edge.u;
        int v = edge.v;

        if (ds.findSet(u) != ds.findSet(v))
        {
            result.push_back(edge);
            ds.unionSets(u, v);
        }
    }

    return result;
}

int main()
{
    int n, m, totalCost = 0;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;
    if (m < n - 1)
    {
        cout << "Number of edges must be greater than or equal to : " << n - 1 << "\n";
        return 1;
    }
    else if (m > n * (n - 1) / 2)
    {
        cout << "Number of edges must be less than or equal to : " << n * (n - 1) / 2 << "\n";
        return 1;
    }

    vector<Edge> edges;

    cout << "Enter edge details (u v w) for each edge:\n";
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    vector<Edge> minimumSpanningTree = kruskalMST(edges, n);

    cout << "\nEdges of the Minimum Spanning Tree:\n";
    for (const Edge &edge : minimumSpanningTree)
    {
        totalCost += edge.weight;
        cout << edge.u << " - " << edge.v << " : " << edge.weight << "\n";
    }
    cout << "Total cost of the Minimum Spanning Tree: " << totalCost << "\n";
    return 0;
}