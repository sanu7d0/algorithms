#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
    fastio;

    int N, M;
    cin >> N >> M;
    priority_queue<int, vector<int>, greater<int>> clean;
    queue<int> dirty;

    int ans = 0;
    for (int x, i = 0; i < N; ++i) {
        cin >> x;
        if (x < 10)
            continue;

        if (x % 10 == 0) {
            if (x == 10)
                ans++;
            else
                clean.push(x);
        } else {
            dirty.push(x);
        }
    }

    while (!clean.empty() && M > 0) {
        int cur = clean.top();
        clean.pop();

        int desire = cur / 10 - 1;
        int actual = min(M, desire);

        M -= actual;
        ans += (desire == actual ? actual + 1 : actual);
    }

    while (!dirty.empty() && M > 0) {
        int cur = dirty.front();
        dirty.pop();

        while (cur >= 10 && M > 0) {
            M--;
            cur -= 10;
            ans++;
        }
    }

    cout << ans << "\n";
}
