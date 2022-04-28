#include <iostream>
#include <math.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
    fastio;

    int N;
    cin >> N;
    if (N < 4) {
        cout << 0 << "\n";
        return 0;
    }

    int k = floor(sqrt(N)); // k^2 <= N < (k+1)^2
    int ans = 0;

    // big square
    for (int i = 1; i < k; ++i)
        ans += i * i;

    // additional squares
    int remain = N - k * k;
    while (remain > 0) {
        int x = (remain <= k ? remain : remain % k);
        ans += (x - 1) * (x) / 2;
        remain -= k;
    }

    cout << ans << "\n";
}
