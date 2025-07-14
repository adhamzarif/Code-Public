#include <bits/stdc++.h>
using namespace std;

#define MX 100
vector<int> graph[MX];
int color[MX]; // -1 = unvisited, 0 and 1 = colors

bool isBipartite(int start, int nodes)
{
    queue<int> q;
    q.push(start);
    color[start] = 0; // Start with color 0

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : graph[u])
        {
            if (color[v] == -1)
            {
                // Assign alternate color to adjacent node
                color[v] = 1 - color[u];
                q.push(v);
            }
            else if (color[v] == color[u])
            {
                // Same color as neighbor → not bipartite
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    // Input edges
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Initialize colors
    for (int i = 0; i < nodes; i++)
    {
        color[i] = -1;
    }

    bool bipartite = true;
    for (int i = 0; i < nodes; i++)
    {
        if (color[i] == -1)
        {
            if (!isBipartite(i, nodes))
            {
                bipartite = false;
                break;
            }
        }
    }

    cout << "Graph is Bipartite: " << (bipartite ? "Yes" : "No") << endl;

    return 0;
}
