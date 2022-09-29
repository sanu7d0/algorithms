#include <algorithm>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;

    int N;
    cin >> N;
    vector<int> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];
    sort(v.begin(), v.end());

    int start = 0, end = N - 1;
    int gap = 2'000'000'000;

    pair<int, int> ans;
    while (start < end) {
        int sum = v[start] + v[end];

        if (gap > abs(sum)) {
            gap = abs(sum);
            ans.first = v[start];
            ans.second = v[end];

            if (sum == 0)
                break;
        }

        if (sum < 0)
            start++;
        else
            end--;
    }

    cout << ans.first << " " << ans.second;
}
