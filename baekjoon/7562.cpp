#include <iostream>
#include <memory.h>
#include <queue>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

constexpr int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
constexpr int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

int L;
bool visited[300][300];

int bfs(int fromX, int fromY, int toX, int toY)
{
    queue<pair<pair<int, int>, int>> q;
    q.push({ { fromX, fromY }, 0 });
    visited[fromY][fromX] = true;

    while (!q.empty()) {
        int x, y, d;
        x = q.front().first.first;
        y = q.front().first.second;
        d = q.front().second;
        q.pop();

        if (x == toX && y == toY)
            return d;

        int tx, ty;
        for (int i = 0; i < 8; ++i) {
            tx = x + dx[i];
            ty = y + dy[i];
            if (tx < 0 || tx >= L || ty < 0 || ty >= L)
                continue;

            if (!visited[ty][tx]) {
                visited[ty][tx] = true;
                q.push({ { tx, ty }, d + 1 });
            }
        }
    }
    return -1;
}

int main()
{
    fastio;

    int T;
    cin >> T;
    while (T--) {
        cin >> L;
        int fx, fy, tx, ty;
        cin >> fx >> fy >> tx >> ty;

        memset(visited, 0, sizeof(visited));
        cout << bfs(fx, fy, tx, ty) << "\n";
    }
}
