#include <iostream>
#include <memory.h>
#include <queue>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N;
int field[52][52]; // zero padding

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int bfs(pair<int, int> root)
{
    field[root.second][root.first] = 2;
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
            if (field[ty][tx] == 1) {
                field[ty][tx] = 2;
                q.emplace(tx, ty);
            }
        }
    }
    return count;
}

void helper(int m, int n, vector<pair<int, int>>& entries)
{
    int count = 0;
    for (auto entry : entries)
        if (field[entry.second][entry.first] == 1 && bfs(entry))
            count++;
    cout << count << "\n";
}

int main()
{
    fastio;

    int T;
    cin >> T;

    while (T--) {
        memset(field, 0, sizeof field);
        int m, n, k;
        cin >> m >> n >> k;

        vector<pair<int, int>> entries;
        for (int x, y, i = 0; i < k; ++i) {
            cin >> x >> y;
            field[y][x] = 1;
            entries.push_back({ x, y });
        }
        helper(m, n, entries);
    }
}
