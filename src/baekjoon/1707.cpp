#include <iostream>
#include <queue>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int V, E;
vector<int> adj[20001];

bool bfs(int root, int color, vector<int>& colors)
{
    queue<int> q;
    q.emplace(root);
    colors[root] = color;

    while (!q.empty()) {
        int u = move(q.front());
        q.pop();

        for (int v : adj[u]) {
            if (colors[v] == 0) {
                q.push(v);
                colors[v] = colors[u] * -1;
            } else if (colors[v] + colors[u] != 0)
                return false;
        }
    }
    return true;
}

bool helper()
{
    vector<int> colors = vector<int>(V + 1, 0);

    for (int i = 1; i <= V; ++i) {
        if (colors[i] != 0)
            continue;

        if (!bfs(i, 1, colors))
            return false;
    }
    return true;
}

int main()
{
    fastio;

    int K;
    cin >> K;
    while (K--) {
        cin >> V >> E;
        int u, v;
        for (int i = 0; i < E; ++i) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << (helper() ? "YES" : "NO") << "\n";

        for (int i = 1; i <= V; ++i)
            adj[i].clear();
    }
}
