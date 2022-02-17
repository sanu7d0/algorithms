#include <algorithm>
#include <functional>
#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

struct Ad {
    int c;    // cost
    int r;    // return
    double e; // efficiency
};

int main() {
    fastio;

    int C, N, cost, ret;
    Ad v[20];

    cin >> C >> N;
    for (int i = 0; i < N; ++i) {
        cin >> cost >> ret;
        v[i] = {cost, ret, (double)ret / cost};
    }

    sort(v, v + N,
         [](Ad fisrt, Ad second) -> bool { return fisrt.r < second.r; });
    sort(v, v + N,
         [](Ad first, Ad second) -> bool { return first.e > second.e; });

    int x, idx = 0;
    cost = ret = 0;
    while (ret < C) {
        x = (C - ret) / v[idx].r;
        ret += x * v[idx].r;
        cost += x * v[idx].c;

        idx++;
    }

    cout << cost << endl;
}
