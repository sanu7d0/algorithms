#include <algorithm>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
    fastio;

    int N;
    cin >> N;

    vector<int> v;
    for (int a, b, i = 0; i < N; ++i) {
        cin >> a >> b;
        v.emplace_back(b - a);
    }

    if (N % 2 != 0) {
        cout << "1\n";
        return 0;
    }

    sort(v.begin(), v.end());

    int ans = v[N / 2] - v[N / 2 - 1] + 1;
    cout << ans << "\n";
}
