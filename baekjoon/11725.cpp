#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N;
vector<vector<int>> graph;
vector<int> parent;
vector<bool> visited;

void dfs(int u, int p)
{
    parent[u] = p;
    visited[u] = true;

    // int v;
    // for (int i = 0; i < graph[u].size(); ++i)
    for (const int v : graph[u])
    {
        // v = graph[u][i];
        if (!visited[v])
            dfs(v, u);
    }
}

void dfs_iterative(int root)
{
    stack<int> s;
    s.push(root);

    while (!s.empty())
    {
        int u = s.top();
        s.pop();

        if (!visited[u])
            visited[u] = true;

        for (const int v : graph[u])
        {
            if (!visited[v])
            {
                parent[v] = u;
                s.push(v);
            }
        }
    }
}

void bfs(int _u, int _p)
{
    queue<pair<int, int>> q;
    q.push({_u, _p});

    while (!q.empty())
    {
        auto [u, p] = q.front();
        q.pop();
        visited[u] = true;
        parent[u] = p;

        int v;
        for (int i = 0; i < graph[u].size(); ++i)
        {
            v = graph[u][i];
            if (!visited[v])
                q.emplace(v, u);
        }
    }
}

int main()
{
    fastio;

    cin >> N;
    graph = vector<vector<int>>(N + 1);
    parent = vector<int>(N + 1, 0);
    visited = vector<bool>(N + 1, false);

    int v1, v2;
    for (int i = 0; i < N; ++i)
    {
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    // dfs(1, 1);
    // bfs(1, 1);
    dfs_iterative(1);
    for (int i = 2; i <= N; ++i)
        cout << parent[i] << "\n";
}
