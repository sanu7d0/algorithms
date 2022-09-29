#include <algorithm>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int left_bound(int x, vector<int>& v)
{
    int left = 0;
    int right = v.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (v[mid] == x)
            right = mid - 1;
        else if (v[mid] < x)
            left = mid + 1;
        else if (v[mid] > x)
            right = mid - 1;
    }

    if (left >= v.size() || v[left] != x)
        return -1;
    return left;
}

int right_bound(int x, vector<int>& v)
{
    int left = 0;
    int right = v.size() - 1;
    int count = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (v[mid] == x)
            left = mid + 1;
        else if (v[mid] < x)
            left = mid + 1;
        else if (v[mid] > x)
            right = mid - 1;
    }

    if (right < 0 || v[right] != x)
        return -1;
    return right;
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
        int l = left_bound(x, v);
        int r = right_bound(x, v);
        if (l == -1 || r == -1)
            cout << 0 << " ";
        else
            cout << r - l + 1 << " ";
    }
}
