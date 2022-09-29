#include <algorithm>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N, M;

void dfs(int u, vector<int> d) {
    d.push_back(u);

    if (d.size() == M) {
        for (auto i : d)
            cout << i << " ";
        cout << "\n";
        return;
    }

    for (int v = 1; v <= N; ++v) {
        dfs(v, d);
    }
}

int main() {
    fastio;

    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        dfs(i, {});
    }
}
