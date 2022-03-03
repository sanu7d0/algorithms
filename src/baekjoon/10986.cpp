#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

typedef long long ll;

int main() {
    fastio;

    int N, M;
    cin >> N >> M;

    ll cnt[1001] = {0};
    ll x, sum = 0, ans = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> x;
        sum += x;
        cnt[sum % M] += 1;
    }

    for (int i = 0; i <= M; ++i) {
        // nCn-1
        ans += cnt[i] * (cnt[i] - 1) / 2;
    }

    cout << ans + cnt[0];
}
