#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
typedef long long ll;

int dp[31][31];

int main() {
    fastio;

    for (int i = 1; i <= 30; ++i)
        dp[1][i] = i;

    for (int i = 2; i <= 30; ++i) {
        for (int j = i; j <= 30; ++j) {
            for (int k = j - 1; k >= 1; --k) {
                dp[i][j] += dp[i - 1][k];
            }
        }
    }

    int T, N, M;
    cin >> T;
    while (T--) {
        cin >> N >> M;
        cout << dp[N][M] << "\n";
    }
    return 0;
}
