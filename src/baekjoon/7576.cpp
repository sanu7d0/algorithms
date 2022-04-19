#include <iostream>
#include <queue>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N, M;
vector<vector<int>> box;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int bfs(queue<pair<pair<int, int>, int>>& tomatoes, int blank)
{
    int young = N * M - tomatoes.size() - blank;
    if (young == 0)
        return 0;

    while (!tomatoes.empty()) {
        auto [x, y] = tomatoes.front().first;
        int d = tomatoes.front().second;
        tomatoes.pop();

        int tx, ty;
        for (int i = 0; i < 4; ++i) {
            tx = x + dx[i];
            ty = y + dy[i];
            if (tx < 0 || tx >= M || ty < 0 || ty >= N)
                continue;

            if (box[ty][tx] == 0) {
                box[ty][tx] = 1;
                young -= 1;
                if (young == 0)
                    return d + 1;

                tomatoes.push({ { tx, ty }, d + 1 });
            }
        }
    }
    return -1;
}

int main()
{
    fastio;

    cin >> M >> N;
    box = vector<vector<int>>(N, vector<int>(M, 0));
    queue<pair<pair<int, int>, int>> tomatoes;

    int blank = 0;
    for (int i = 0; i < N; ++i) {
        for (int toma, j = 0; j < M; ++j) {
            cin >> toma;
            box[i][j] = toma;
            if (toma == 1)
                tomatoes.push({ { j, i }, 0 });
            else if (toma == -1)
                blank++;
        }
    }

    cout << bfs(tomatoes, blank);
}
