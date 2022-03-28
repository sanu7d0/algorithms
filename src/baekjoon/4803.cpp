#include <algorithm>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m;
vector<int> adj[501];
bool visited[501];
bool hasCycle;

void dfs(int u, int p)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
            dfs(v, u);
        else if (v != p)
            hasCycle = true;
    }
}

int forest()
{
    int trees = 0;
    for (int i = 1; i <= n; ++i)
    {
        hasCycle = false;
        if (!visited[i])
        {
            dfs(i, 0);
            if (!hasCycle)
                trees += 1;
        }
    }
    return trees;
}

int main()
{
    fastio;

    cin >> n >> m;
    int caseNum = 1;
    while (!(n == 0 && m == 0))
    {
        int v1, v2;
        for (int i = 0; i < m; ++i)
        {
            cin >> v1 >> v2;
            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }

        cout << "Case " << caseNum << ": ";
        int trees = forest();
        switch (trees)
        {
        case 0:
            cout << "No trees.\n";
            break;
        case 1:
            cout << "There is one tree.\n";
            break;
        default:
            cout << "A forest of " << trees << " trees.\n";
        }

        // Clear graphs
        for (int i = 1; i <= n; ++i)
            adj[i].clear();
        fill(visited, visited + n + 1, false);
        cin >> n >> m;
        caseNum += 1;
    }
}
