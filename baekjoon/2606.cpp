#include <iostream>
#include <queue>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

vector<int> adj[101];

int bfs(int root, int N)
{
    queue<int> q;
    vector<bool> visited = vector<bool>(N + 1, false);
    int count = 0;

    q.push(root);
    visited[root] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        count += 1;
        // cout << u << "\n";

        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    return count;
}

int main()
{
    fastio;

    int N, M;
    cin >> N >> M;
    for (int a, b, i = 0; i < M; ++i)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << bfs(1, N) - 1;
}
