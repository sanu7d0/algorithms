#include <algorithm>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int binarySearch(int x, vector<int>& v)
{
    int left = 0;
    int right = v.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (v[mid] == x)
            return mid;
        else if (v[mid] < x)
            left = mid + 1;
        else if (v[mid] > x)
            right = mid - 1;
    }
    return -1;
}

int main()
{
    fastio;

    int N, M;
    vector<int> v;

    cin >> N;
    v.reserve(N);
    for (int x, i = 0; i < N; ++i) {
        cin >> x;
        v.emplace_back(x);
    }
    sort(v.begin(), v.end());

    cin >> M;
    for (int x, i = 0; i < M; ++i) {
        cin >> x;
        cout << (binarySearch(x, v) != -1 ? 1 : 0) << "\n";
    }
}
