#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N;
vector<vector<int>> town;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int bfs(pair<int, int> root, int id)
{
    town[root.first][root.second] = id;
    queue<pair<int, int>> q;
    q.push(root);

    int count = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        count++;

        for (int tx, ty, i = 0; i < 4; ++i) {
            tx = x + dx[i];
            ty = y + dy[i];
            if (town[tx][ty] == 1) {
                town[tx][ty] = id;
                q.emplace(tx, ty);
            }
        }
    }
    return count;
}

void helper()
{
    vector<int> ans;
    int id = 2;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (town[i][j] != 1)
                continue;

            int c = bfs({ i, j }, id);
            if (c > 0) {
                ans.push_back(c);
                id++;
            }
        }
    }
    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (const int i : ans) {
        cout << i << "\n";
    }
}

int main()
{
    fastio;

    cin >> N;
    cin.ignore();
    town = vector<vector<int>>(N + 2, vector<int>(N + 2, 0)); // zero padding for border

    string buf;
    for (int i = 0; i < N; ++i) {
        getline(cin, buf);
        for (int j = 0; j < N; ++j) {
            town[i + 1][j + 1] = buf[j] - '0';
        }
    }

    helper();
}
