#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>>& graph, int start)
{
    vector<bool> visited(graph.size(), false);
    vector<int> distance(graph.size(), -1);

    queue<int> q;

    visited[start] = true;
    distance[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);
            }
        }
    }

    cout << "\nShortest distances from node " << start << ":\n";
    for (int i = 0; i < graph.size(); i++)
    {
        cout << "Node " << i << " -> Distance: " << distance[i] << endl;
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
        graph[v].push_back(u);
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    BFS(graph, start);

    return 0;
}