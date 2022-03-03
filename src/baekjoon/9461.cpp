#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
typedef long long ll;

int main() {
    fastio;

    ll d[101];
    d[1] = d[2] = d[3] = 1;
    d[4] = d[5] = 2;

    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        if (N <= 5) {
            cout << d[N] << "\n";
            continue;
        }

        for (int i = 6; i <= N; ++i) {
            d[i] = d[i - 1] + d[i - 5];
        }
        cout << d[N] << "\n";
    }
}
