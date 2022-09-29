#include <algorithm>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
typedef long long ll;

ll asec[64][10] = {0};

ll dp(int level, int n) {
    if (level == 1)
        return 10 - n;
    if (asec[level][n] > 0)
        return asec[level][n];

    ll sum = 0;
    for (int i = n; i <= 9; i++) {
        sum += dp(level - 1, i);
    }
    asec[level][n] = sum;

    return sum;
}

int main() {
    fastio;

    for (int i = 0; i < 10; i++) {
        asec[1][i] = 10 - i;
        asec[0][i] = 1;
    }

    int T, n;
    ll res;
    cin >> T;
    while (T--) {
        cin >> n;

        res = 0;
        for (int i = 0; i < 10; i++) {
            res += dp(n - 1, i);
        }

        cout << res << "\n";
    }
}
