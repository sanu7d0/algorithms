#include <iostream>
#include <queue>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

using piii = pair<int, pair<int, int>>;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
    fastio;

    int N, K, S, X, Y;
    cin >> N >> K;
    vector<vector<int>> map(N + 1, vector<int>(N + 1, 0));
    priority_queue<piii, vector<piii>, greater<piii>> pq;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            int v;
            cin >> v;
            map[i][j] = v;
            if (v > 0)
                pq.push({v, {i, j}});
        }
    }

    cin >> S >> X >> Y;

    for (int i = 0; i < S; ++i)
    {
        vector<piii> temp;
        while (!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();

            for (int j = 0; j < 4; ++j)
            {
                int x = cur.second.first + dx[j];
                int y = cur.second.second + dy[j];

                if (y >= 1 && x >= 1 && y <= N && x <= N && map[x][y] == 0)
                {
                    map[x][y] = cur.first;
                    temp.push_back({cur.first, {x, y}});
                }
            }
        }

        for (auto e : temp)
            pq.push(e);
    }

    cout << map[X][Y] << endl;
}
