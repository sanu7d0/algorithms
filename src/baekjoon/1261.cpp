#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define INF 1000000000

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int N, M;
int maze[101][101];

int bfs(pair<int, int> root)
{
    int dist[101][101];
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            dist[i][j] = INF;
    dist[root.first][root.second] = 0;

    deque<pair<pair<int, int>, int>> dq;
    dq.push_front({ root, 0 });

    int res = INF;
    while (!dq.empty()) {
        int x = dq.front().first.first;
        int y = dq.front().first.second;
        int cost = dq.front().second;
        dq.pop_front();

        if (dist[y][x] < cost)
            continue;

        if (x == M && y == N)
            res = min(res, cost);

        for (int i = 0; i < 4; ++i) {
            int tx = x + dx[i];
            int ty = y + dy[i];

            if (!(tx >= 1 && tx <= M && ty >= 1 && ty <= N))
                continue;

            int weight = maze[ty][tx];
            int nextCost = cost + weight;
            if (nextCost < dist[ty][tx]) {
                dist[ty][tx] = nextCost;

                if (weight == 1)
                    dq.push_back({ { tx, ty }, nextCost });
                else
                    dq.push_front({ { tx, ty }, nextCost });
            }
        }
    }

    return res;
}

int main()
{
    fastio;

    cin >> M >> N;
    for (int i = 1; i <= N; ++i) {
        string line;
        cin >> line;
        for (int j = 1; j <= M; ++j)
            maze[i][j] = line[j - 1] == '1';
    }

    cout << bfs({ 1, 1 }) << "\n";
}
