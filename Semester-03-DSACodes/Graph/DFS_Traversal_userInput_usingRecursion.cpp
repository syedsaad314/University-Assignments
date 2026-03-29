#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int>>& graph, vector<bool>& visited, int node)
{
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
        {
            DFS(graph, visited, neighbor);
        }
    }
}

int main()
{
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V);

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u); // undirected
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    vector<bool> visited(V, false);

    cout << "DFS Traversal: ";
    DFS(graph, visited, start);

    return 0;
}