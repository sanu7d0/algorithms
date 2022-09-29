#include <algorithm>
#include <iostream>
#include <queue>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int arr[1'000'000];
int lis[1'000'000] {};

int binary_search(int left, int right, int target)
{
    while (left < right) {
        int mid = (left + right) / 2;

        if (lis[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return right;
}

int main()
{
    fastio;

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int i = 1, j = 0;
    lis[0] = arr[0];

    while (i < N) {
        if (lis[j] < arr[i]) {
            lis[++j] = arr[i];
        } else {
            int idx = binary_search(0, j, arr[i]);
            lis[idx] = arr[i];
        }
        i++;
    }

    cout << j + 1;
}
