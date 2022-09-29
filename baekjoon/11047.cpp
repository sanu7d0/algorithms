#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;

    int N, K;
    vector<int> v;

    cin >> N >> K;
    v = vector<int>(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i];

    int sum = 0, cnt = 0;
    int i = N - 1;
    while (sum < K) {
        int coins = (K - sum) / v[i];
        cnt += coins;
        sum += coins * v[i];
        i--;
    }

    cout << cnt;
}
