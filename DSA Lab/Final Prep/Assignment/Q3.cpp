#include <bits/stdc++.h>
using namespace std;

// DFS traversal
void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited)
{
    visited[node] = true;
    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
            dfs(neighbor, graph, visited);
    }
}

// checking if there exists at least one vertex from which all vertices are reachable
bool existsVertexThatReachesAll(int V, vector<vector<int>> &graph)
{
    for (int i = 0; i < V; i++)
    {
        vector<bool> visited(V, false);
        dfs(i, graph, visited);
        bool canReachAll = true;
        for (int j = 0; j < V; j++)
        {
            if (!visited[j])
            {
                canReachAll = false;
                break;
            }
        }
        if (canReachAll)
        {
            return true;
        } // checking if one vertex that reaches all others found
    }
    return false; // no vertex found
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> graph(V);
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v); // directed graph
    }

    if (existsVertexThatReachesAll(V, graph))
    {
        cout << "Gráfico no no completamente conectado" << endl;
    }
    else
    {
        cout << "Gráfico no completamente conectado" << endl;
    }

    return 0;
}