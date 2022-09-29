#include <algorithm>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;

    int N, C;
    cin >> N >> C;
    vector<int> house;

    for (int x, i = 0; i < N; ++i) {
        cin >> x;
        house.push_back(x);
    }
    sort(house.begin(), house.end());

    int left, right, result;
    left = 0;
    right = house[N - 1];
    result = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        int router = C - 1; // pre-installed at 0
        int i = 0, dist = 0;
        while (router > 0 && i < N - 1) {
            i++;
            dist += house[i] - house[i - 1];

            if (dist < mid)
                continue;

            dist = 0;
            router--;
        }

        if (router > 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
            result = max(result, mid);
        }
    }

    cout << result;
}
