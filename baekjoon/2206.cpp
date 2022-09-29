#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

struct Movement {
    int x, y, d, skill, id;
};

int N, M;
vector<vector<int>> map;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void showMap()
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

int bfs(int _x, int _y)
{
    int newId = INT32_MAX;
    vector<int> result;
    queue<Movement> q;
    q.push({ _x, _y, 1, 1, newId });
    map[_y][_x] = newId;

    while (!q.empty()) {
        auto [x, y, d, skill, id] = q.front();
        q.pop();

        if (x == M - 1 && y == N - 1) {
            result.push_back(d);
            continue;
        }

        int tx, ty;
        for (int i = 0; i < 4; ++i) {
            tx = x + dx[i];
            ty = y + dy[i];
            if (tx < 0 || tx >= M || ty < 0 || ty >= N)
                continue;

            int target = map[ty][tx];
            if (target != 1 && (target == 0 || id > target)) {
                map[ty][tx] = id;
                q.push({ tx, ty, d + 1, skill, id });
            } else if (skill > 0 && target == 1) {
                q.push({ tx, ty, d + 1, skill - 1, --newId });
            }
        }
        // showMap();
    }
    return result.size() == 0 ? -1 : *max_element(result.begin(), result.end());
}

int main()
{
    fastio;

    cin >> N >> M;
    cin.ignore();

    map = vector<vector<int>>(N, vector<int>(M, 0));

    string buf;
    for (int i = 0; i < N; ++i) {
        getline(cin, buf);
        for (int j = 0; j < M; ++j)
            map[i][j] = buf[j] == '0' ? 0 : 1;
    }

    cout << bfs(0, 0);
}
