#include <iostream>
#include <queue>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N, M, H;
vector<vector<vector<int>>> box;

int dx[6] = { 0, 0, 1, -1, 0, 0 };
int dy[6] = { 1, -1, 0, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

struct Point {
    int x, y, z;
};

int bfs(queue<pair<Point, int>>& tomatoes, int blank)
{
    int young = N * M * H - tomatoes.size() - blank;
    if (young == 0)
        return 0;

    while (!tomatoes.empty()) {
        auto [x, y, z] = tomatoes.front().first;
        int d = tomatoes.front().second;
        tomatoes.pop();

        int tx, ty, tz;
        for (int i = 0; i < 6; ++i) {
            tx = x + dx[i];
            ty = y + dy[i];
            tz = z + dz[i];
            if (tx < 0 || tx >= M || ty < 0 || ty >= N || tz < 0 || tz >= H)
                continue;

            if (box[tz][ty][tx] == 0) {
                box[tz][ty][tx] = 1;

                young--;
                if (young == 0)
                    return d + 1;

                tomatoes.push({ { tx, ty, tz }, d + 1 });
            }
        }
    }
    return -1;
}

int main()
{
    fastio;

    cin >> M >> N >> H;
    box = vector<vector<vector<int>>>(H,
        vector<vector<int>>(N,
            vector<int>(M, 0)));
    queue<pair<Point, int>> tomatoes;

    int blank = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int toma, k = 0; k < M; ++k) {
                cin >> toma;
                box[i][j][k] = toma;
                if (toma == 1)
                    tomatoes.push({ { k, j, i }, 0 });
                else if (toma == -1)
                    blank++;
            }
        }
    }

    cout << bfs(tomatoes, blank);
}
