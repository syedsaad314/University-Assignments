#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS_Iterative(vector<vector<int>>& graph, int start)
{
    vector<bool> visited(graph.size(), false);
    stack<int> st;

    st.push(start);

    cout << "DFS Traversal (Iterative): ";

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (!visited[node])
        {
            visited[node] = true;
            cout << node << " ";

            // push neighbors in reverse order
            for (int i = graph[node].size() - 1; i >= 0; i--)
            {
                int neighbor = graph[node][i];
                if (!visited[neighbor])
                {
                    st.push(neighbor);
                }
            }
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
        graph[v].push_back(u);
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    DFS_Iterative(graph, start);

    return 0;
}