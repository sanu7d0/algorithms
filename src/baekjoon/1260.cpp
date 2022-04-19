#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

vector<int> adj[1001];

void dfs(int u, vector<bool> &visited)
{
    visited[u] = true;
    cout << u << " ";

    for (int v : adj[u])
        if (!visited[v])
            dfs(v, visited);
}

void bfs(int root, int N)
{
    vector<bool> visited = vector<bool>(N + 1, false);
    queue<int> q;
    q.push(root);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        visited[u] = true;
        cout << u << " ";

        for (int v : adj[u])
            if (!visited[v])
                q.push(v);
    }
}

int main()
{
    fastio;

    int N, M, V;
    cin >> N >> M >> V;
    for (int a, b, i = 0; i < M; ++i)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= N; ++i)
        sort(adj[i].begin(), adj[i].end());

    vector<bool> visited = vector<bool>(N + 1, false);
    dfs(V, visited);
    cout << endl;
    bfs(V, N);
}
