#include <algorithm>
#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using u64 = unsigned long long;

int main()
{
    fastio;

    u64 N, k;
    cin >> N >> k;

    u64 left = 1, right = k, result = 0;
    while (left <= right) {
        u64 mid = (left + right) / 2;

        u64 total = 0;
        for (int i = 1; i <= N; ++i) {
            total += min(mid / i, N);
        }

        if (total >= k) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << result << "\n";
}
