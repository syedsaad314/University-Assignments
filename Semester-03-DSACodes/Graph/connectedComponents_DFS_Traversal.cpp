#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int>>& graph, vector<bool>& visited, int node)
{
    visited[node] = true;

    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
        {
            DFS(graph, visited, neighbor);
        }
    }
}

int countComponents(vector<vector<int>>& graph, int V)
{
    vector<bool> visited(V, false);
    int count = 0;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            DFS(graph, visited, i);
            count++;
        }
    }

    return count;
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
        graph[v].push_back(u);
    }

    int components = countComponents(graph, V);

    cout << "Total Connected Components: " << components << endl;

    return 0;
}