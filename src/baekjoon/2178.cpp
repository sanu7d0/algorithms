#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N, M;
vector<vector<bool>> maze;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int bfs(int x_, int y_)
{
    queue<pair<pair<int, int>, int>> q;
    q.push({ { x_, y_ }, 1 });
    maze[y_][x_] = false;

    int d, x, y, tx, ty;
    while (!q.empty()) {
        x = q.front().first.first;
        y = q.front().first.second;
        d = q.front().second;
        q.pop();

        if (x == M - 1 && y == N - 1)
            return d;

        for (int i = 0; i < 4; ++i) {
            tx = x + dx[i];
            ty = y + dy[i];
            if (tx < 0 || tx >= M || ty < 0 || ty >= N)
                continue;

            if (maze[ty][tx]) {
                maze[ty][tx] = false;
                q.push({ { tx, ty }, d + 1 });
            }
        }
    }
    return -1;
}

int main()
{
    fastio;

    cin >> N >> M;
    cin.ignore();

    maze = vector<vector<bool>>(N, vector<bool>(M, false));

    string buf;
    for (int i = 0; i < N; ++i) {
        getline(cin, buf);
        for (int j = 0; j < M; ++j) {
            if (buf[j] == '1')
                maze[i][j] = true;
        }
    }

    cout << bfs(0, 0);
}
