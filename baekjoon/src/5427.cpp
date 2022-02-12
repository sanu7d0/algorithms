#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int w, h, t;
vector<vector<char>> map;
vector<vector<bool>> visited;

queue<pair<int, int>> fq;
queue<pair<int, int>> pq;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool bfs() {
    t = 0;

    while (!pq.empty()) {
        int fqsize = fq.size();
        int pqsize = pq.size();
        int x, y, nx, ny;

        t++;

        // fire
        while (fqsize--) {
            x = fq.front().first;
            y = fq.front().second;
            fq.pop();
            for (int d = 0; d < 4; ++d) {
                nx = x + dx[d];
                ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= h || ny >= w)
                    continue;
                if (map[nx][ny] == '#' || visited[nx][ny])
                    continue;

                fq.push({nx, ny});
                visited[nx][ny] = true;
            }
        }

        // player
        while (pqsize--) {
            x = pq.front().first;
            y = pq.front().second;
            pq.pop();
            for (int d = 0; d < 4; ++d) {
                nx = x + dx[d];
                ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= h || ny >= w) {
                    // escape
                    return true;
                }
                if (map[nx][ny] == '#' || visited[nx][ny])
                    continue;

                pq.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    char c;

    cin >> T;
    while (T--) {
        cin >> w >> h;
        map = vector<vector<char>>(h);
        visited = vector<vector<bool>>(h, vector<bool>(w, false));
        while (!fq.empty())
            fq.pop();
        while (!pq.empty())
            pq.pop();

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> c;
                map[i].push_back(c);
                if (c == '@') {
                    pq.push({i, j});
                    map[i][j] = '.';
                    visited[i][j] = true;
                } else if (c == '*') {
                    fq.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        cout << (bfs() ? to_string(t) : "IMPOSSIBLE") << "\n";
    }
}
