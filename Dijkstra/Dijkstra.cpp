#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

#define INF std::numeric_limits<int>::max()

class Graph
{
public:
    int V;
    std::vector<std::vector<std::pair<int, int>>> adj;

    Graph(int vertices) : V(vertices), adj(vertices) {}

    void addEdge(int u, int v, int weight)
    {
        adj[u].emplace_back(v, weight);
        adj[v].emplace_back(u, weight);
    }
};

void initializeSingleSource(Graph &G, int s, std::vector<int> &d, std::vector<int> &pi)
{
    for (int v = 0; v < G.V; ++v)
    {
        d[v] = INF;
        pi[v] = -1; // Assuming NIL is represented by -1
    }
    d[s] = 0;
}

void relax(int u, int v, int weight, std::vector<int> &d, std::vector<int> &pi)
{
    if (d[v] > d[u] + weight)
    {
        d[v] = d[u] + weight;
        pi[v] = u;
    }
}

int extractMin(std::vector<int> &Q, std::vector<int> &d)
{
    int u = Q[0];
    for (int v : Q)
    {
        if (d[v] < d[u])
            u = v;
    }
    Q.erase(std::remove(Q.begin(), Q.end(), u), Q.end());
    return u;
}

void dijkstra(Graph &G, int s)
{
    std::vector<int> d(G.V, INF); // Distance from source
    std::vector<int> pi(G.V, -1); // Predecessor
    std::vector<int> Q(G.V);      // Priority queue

    for (int i = 0; i < G.V; ++i)
        Q[i] = i;

    initializeSingleSource(G, s, d, pi);

    while (!Q.empty())
    {
        int u = extractMin(Q, d);
        for (auto &neighbor : G.adj[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;
            relax(u, v, weight, d, pi);
        }
    }

    // Print the result (distance from source and predecessor)
    for (int i = 0; i < G.V; ++i)
    {
        std::cout << "Vertex " << i << ": Distance = " << d[i] 
        << ", Predecessor = " << (pi[i] == -1 ? "NULL" : std::to_string(pi[i])) 
        << std::endl;
    }
}

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    if (E > V * (V - 1) / 2)
    {
        cout << "Error: Too many edges" << endl;
        return 0;
    }
    else if (E < V - 1)
    {
        cout << "Error: Too few edges" << endl;
        return 0;
    }
    Graph G(V);
    cout << "Enter the edges (u, v, w) : " << endl;
    for (int i = 0; i < E; ++i)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        G.addEdge(u, v, weight);
    }
    int s;
    cout << "Enter the source vertex: ";
    cin >> s;
    dijkstra(G, s);
    return 0;
}
