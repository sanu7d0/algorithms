#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N;
vector<array<int, 3>> v;
vector<array<int, 3>> memo;

int dp(int n, int right_color) {
    if (n == 0)
        return 0;

    if (memo[n][right_color] > 0) {
        return memo[n][right_color];
    }

    int res = 1000000;
    for (int i = 0; i < 3; ++i)
        if (i != right_color)
            res = min(res, dp(n - 1, i) + v[n][i]);
    memo[n][right_color] = res;

    return res;
}

int main() {
    fastio;

    cin >> N;
    v = vector<array<int, 3>>(N + 1);
    memo = vector<array<int, 3>>(N + 1, array<int, 3>{0, 0, 0});

    for (int i = 1; i <= N; ++i) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    dp(N, 0);
    dp(N, 1);
    dp(N, 2);
    cout << min({memo[N][0], memo[N][1], memo[N][2]});
}
