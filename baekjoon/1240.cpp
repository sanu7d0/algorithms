#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N;
vector<pair<int, int>> adj[1001];

int bfs(int root, int target)
{
    vector<bool> visited(N + 1, false);
    queue<pair<int, int>> q;
    q.push({ root, 0 });
    visited[root] = true;

    while (!q.empty()) {
        int u = q.front().first;
        int d = q.front().second;
        q.pop();

        if (u == target)
            return d;

        for (auto v : adj[u]) {
            if (!visited[v.first]) {
                visited[v.first] = true;
                q.push({ v.first, d + v.second });
            }
        }
    }

    return -1;
}

int main()
{
    fastio;

    int M;
    cin >> N >> M;
    for (int a, b, d, i = 0; i < N - 1; ++i) {
        cin >> a >> b >> d;
        adj[a].push_back({ b, d });
        adj[b].push_back({ a, d });
    }

    for (int a, b, i = 0; i < M; ++i) {
        cin >> a >> b;
        cout << bfs(a, b) << "\n";
    }
}
