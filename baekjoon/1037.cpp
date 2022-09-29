#include <algorithm>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;

    int C;
    cin >> C;
    vector<int> v = vector<int>(C);

    for (int i = 0; i < C; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    if (C == 1)
        cout << v[0] * v[0];
    else {
        cout << v[0] * v[C - 1];
    }
}