#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n;
vector<vector<int>> v;
vector<vector<int>> memo;

int dp(int f, int i) {
    if (f == n)
        return v[n][i];

    if (memo[f][i] > 0)
        return memo[f][i];

    int res = max(dp(f + 1, i), dp(f + 1, i + 1)) + v[f][i];
    memo[f][i] = res;
    return res;
}

int main() {
    fastio;

    cin >> n;
    v = vector<vector<int>>(n + 1);
    memo = vector<vector<int>>(n + 1);

    for (int i = 1; i <= n; ++i) {
        int x;
        for (int j = 0; j < i; ++j) {
            cin >> x;
            v[i].push_back(x);
        }
        memo[i] = vector<int>(i, 0);
    }

    cout << dp(1, 0);
}
