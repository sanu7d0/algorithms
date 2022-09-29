#include <algorithm>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;

    int N;
    cin >> N;
    vector<int> v = vector<int>(N);

    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    for (int i = 0; i <= v[0]; ++i) {
        for (int j = 0; j < N; ++j) {
            if (v[j])
        }
    }
}
