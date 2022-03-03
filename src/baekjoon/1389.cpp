#include <iostream>
#include <queue>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

vector<int> adj[101];

int min_edge_bfs(int u, int t, int n) {
    vector<bool> visited(n, false);
    vector<int> distance(n, 0);
    visited[u] = true;
    distance[u] = 0;

    queue<int> q;
    q.push(u);
    int v;
    while (!q.empty()) {
        v = q.front();
        q.pop();

        for (int i = 0; i < adj[v].size(); i++) {
            if (visited[adj[v][i]])
                continue;

            distance[adj[v][i]] = distance[v] + 1;
            q.push(adj[v][i]);
            visited[adj[v][i]] = true;
        }
    }

    return distance[t];
}

int main() {
    fastio;

    int N, M;
    cin >> N >> M;

    int f1, f2;
    for (int i = 0; i < M; i++) {
        cin >> f1 >> f2;
        adj[f1].push_back(f2);
        adj[f2].push_back(f1);
    }

    int min_total = 10000;
    int ans;
    for (int i = N; i >= 1; i--) {

        int total = 0;
        for (int j = 1; j <= N; j++) {
            total += min_edge_bfs(i, j, N + 1);
        }

        if (total <= min_total) {
            min_total = total;
            ans = i;
        }
    }
    cout << ans << "\n";
}
