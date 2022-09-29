#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

typedef pair<int, int> pii;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int N, M;
vector<vector<char>> map;

vector<char> split_input(string s) {
    vector<char> res;
    for (int i = 0; i < M; ++i)
        res.push_back(s.at(i));
    return res;
}

int bfs(int rootx, int rooty) {
    queue<pair<int, pii>> q;
    q.push({0, {rootx, rooty}});
    vector<vector<bool>> visited =
        vector<vector<bool>>(N, vector<bool>(M, false));
    visited[rooty][rootx] = true;

    int d, x, y, tx, ty;
    int d_max = 0;
    while (!q.empty()) {
        d = q.front().first;
        x = q.front().second.first;
        y = q.front().second.second;
        q.pop();

        d_max = d > d_max ? d : d_max;

        for (int i = 0; i < 4; ++i) {
            tx = x + dx[i];
            ty = y + dy[i];
            if (0 <= tx && tx < M && 0 <= ty && ty < N && map[ty][tx] == 'L' &&
                !visited[ty][tx]) {
                visited[ty][tx] = true;
                q.push({d + 1, {tx, ty}});
            }
        }
    }

    return d_max;
}

int main() {
    fastio;

    cin >> N >> M;
    string s;
    for (int i = 0; i < N; ++i) {
        cin >> s;
        map.push_back(split_input(s));
    }

    int d, d_max = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (map[i][j] == 'L') {
                d = bfs(j, i);
                d_max = d > d_max ? d : d_max;
            }
        }
    }
    cout << d_max;
}
