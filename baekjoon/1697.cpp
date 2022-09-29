#include <iostream>
#include <memory.h>
#include <queue>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
    fastio;

    int n, k;
    bool visited[200'000];
    queue<pair<int, int>> q;

    cin >> n >> k;

    memset(visited, 0, sizeof(visited));
    q.push({ n, 0 });
    visited[n] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int t = q.front().second;
        q.pop();

        if (x == k) {
            cout << t << "\n";
            break;
        }

        if (x - 1 >= 0 && !visited[x - 1]) {
            visited[x - 1] = true;
            q.emplace(x - 1, t + 1);
        }
        if (x + 1 <= k && !visited[x + 1]) {
            visited[x + 1] = true;
            q.emplace(x + 1, t + 1);
        }
        if (x < k && !visited[2 * x]) {
            visited[2 * x] = true;
            q.emplace(2 * x, t + 1);
        }
    }
}
