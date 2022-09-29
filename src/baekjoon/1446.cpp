#include <iostream>
#include <queue>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define INF 1000000000

int N, D;
vector<pair<int, int>> adj[10001];

int dijkstra(int from, int to)
{
    vector<int> dist(D + 1, INF);
    dist[from] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({ from, 0 });

    while (!pq.empty()) {
        int cur = pq.top().first;
        int d = -pq.top().second;
        pq.pop();

        if (dist[cur] < d)
            continue;

        for (auto edge : adj[cur]) {
            int next = edge.first;
            int nextDist = d + edge.second;

            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({ next, -nextDist });
            }
        }
    }

    return dist[to];
}

int main()
{
    fastio;

    cin >> N >> D;

    for (int i = 0; i < N; ++i) {
        int start, end, dist;
        cin >> start >> end >> dist;

        // Not a true shortcut
        if (end > D || end - start <= dist)
            continue;

        adj[start].push_back({ end, dist });
    }

    for (int i = 0; i < D; ++i) {
        adj[i].push_back({ i + 1, 1 });
    }

    cout << dijkstra(0, D) << "\n";
}
