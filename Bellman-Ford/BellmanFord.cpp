#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Edge
{
    int u, v;
    int w;
};

struct Graph
{
    int V, E;
    vector<Edge> edges;

    void addEdge(int u, int v, int w)
    {
        edges.push_back({u, v, w});
    }
};

void InitializeSingleSource(Graph &g, vector<int> &dist, vector<int> &pred, int source)
{
    dist.resize(g.V, numeric_limits<int>::max());
    pred.resize(g.V, -1);
    dist[source] = 0;
}

void Relax(int u, int v, int weight, vector<int> &dist, vector<int> &pred)
{
    if (dist[v] > dist[u] + weight)
    {
        dist[v] = dist[u] + weight;
        pred[v] = u;
    }
}

bool BellmanFord(Graph &g, int source, vector<int> &dist, vector<int> &pred)
{
    InitializeSingleSource(g, dist, pred, source);

    for (int i = 1; i < g.V; ++i)
    {
        for (auto &edge : g.edges)
        {
            Relax(edge.u, edge.v, edge.w, dist, pred);
        }
    }

    for (auto &edge : g.edges)
    {
        if (dist[edge.v] > dist[edge.u] + edge.w)
        {
            return false;
        }
    }

    return true;
}

void PrintPath(const vector<int> &pred, int v)
{
    if (v < 0)
    {
        return;
    }
    PrintPath(pred, pred[v]);
    if (pred[v] >= 0)
    {
        cout << " -> ";
    }
    cout << v;
}

int main()
{
    Graph g;
    cout << "Enter number of vertices : ";
    cin >> g.V;
    cout << "Enter number of edges : ";
    cin >> g.E;
    if (g.E < g.V - 1)
    {
        cout << "Graph is not connected!\n";
        return 0;
    }
    else if (g.E > g.V * (g.V - 1) / 2)
    {
        cout << "Graph is not simple!\n";
        return 0;
    }

    cout << "Enter the edges (u, v, w) :\n";
    for (int i = 0; i < g.E; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    int source;
    cout << "Enter source vertex : ";
    cin >> source;

    vector<int> dist, pred;
    if (BellmanFord(g, source, dist, pred))
    {
        cout << "Shortest paths from " << source << " :\n";
        for (int i = 0; i < g.V; ++i)
        {
            cout << "Distance to " << i << " : " << dist[i] << "\n";
            cout << "Path : ";
            PrintPath(pred, i);
            cout << "\n";
        }
    }
    else
    {
        cout << "Negative weight cycle detected!\n";
    }

    return 0;
}