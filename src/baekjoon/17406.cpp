#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
typedef vector<vector<int>> vvi;

int N, M, K;
vvi v;
vector<array<int, 3>> rot;

void swap(int r1, int c1, int r2, int c2, vvi *v) {
    int tmp = (*v)[r1][c1];
    (*v)[r1][c1] = (*v)[r2][c2];
    (*v)[r2][c2] = tmp;
}

void rotate(int R, int C, int S, vvi *v) {
    for (int s = 1; s <= S; ++s) {
        // left side - topdown
        for (int r = R - s; r < R + s; ++r) {
            swap(r, C - s, r + 1, C - s, v);
        }

        // bottom side - left to right
        for (int c = C - s; c < C + s; ++c) {
            swap(R + s, c, R + s, c + 1, v);
        }

        // right side - bottom up
        for (int r = R + s; r > R - s; --r) {
            swap(r, C + s, r - 1, C + s, v);
        }

        // top side - right to left
        for (int c = C + s; c > C - s + 1; --c) {
            swap(R - s, c, R - s, c - 1, v);
        }
    }
}

int matrix_sum(vvi *v) {
    int res = 1000000;
    int sum;
    for (int i = 0; i < N; ++i) {
        sum = 0;
        for (int j = 0; j < M; ++j) {
            sum += (*v)[i][j];
        }
        res = min(res, sum);
    }
    return res;
}

int dfs(int u, vvi v, vector<bool> visited) {
    visited[u] = true;
    rotate(rot[u][0] - 1, rot[u][1] - 1, rot[u][2], &v);

    int res = 1000000;
    bool end = true;
    for (int i = 0; i < K; ++i) {
        if (!visited[i]) {
            end = false;
            res = min(res, dfs(i, v, visited));
        }
    }

    if (end) {
        res = matrix_sum(&v);
    }

    return res;
}

int main() {
    fastio;

    cin >> N >> M >> K;

    v = vector<vector<int>>(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> v[i][j];

    rot = vector<array<int, 3>>(K);
    for (int i = 0; i < K; ++i)
        cin >> rot[i][0] >> rot[i][1] >> rot[i][2];

    // find minimum
    int res = 1000000;
    for (int i = 0; i < K; ++i) {
        res = min(res, dfs(i, {v.begin(), v.end()}, vector<bool>(K, false)));
    }
    cout << res;
}
