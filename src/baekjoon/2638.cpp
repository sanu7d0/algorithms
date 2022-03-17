#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
typedef pair<int, int> pii;

int N, M;
vector<vector<int>> paper;

int di[4] = {0, 1, 0, -1};
int dj[4] = {-1, 0, 1, 0};

bool in_range(int i, int j) { return 0 <= i && i < N && 0 <= j && j < M; }

// bfs
bool is_inner_space(int _i, int _j) {
    queue<pii> q;
    vector<vector<bool>> visited = vector<vector<bool>>(N, vector<bool>(M, false));

    q.push({_i, _j});
    int i, j;
    while (!q.empty()) {
        pii u = q.front();
        q.pop();
        i = u.first;
        j = u.second;

        // Reached outside
        if (i == 0 || i == N - 1 || j == 0 || j == M - 1)
            return true;

        for (int d = 0; d < 4; ++d) {
            int vi = i + di[d];
            int vj = j + dj[d];
            if (in_range(vi, vj) && !visited[vi][vj] && paper[i][j] == 0) {
                visited[vi][vj] = true;
                q.push({vi, vj});
            }
        }
    }
    return false;
}

bool check_melt(int i, int j) {
    if (paper[i][j] != 1)
        return false;

    int res = 0;
    int vi, vj;
    for (int d = 0; d < 4; ++d) {
        int vi = i + di[d];
        int vj = j + dj[d];
        if (in_range(i - 1, j) && paper[vi][vj] == 0 && is_inner_space(vi, vj)) {
            res += 1;
            if (res >= 2)
                return true;
        }
    }
    return false;
}

int main() {
    fastio;

    cin >> N >> M;
    paper = vector<vector<int>>(N, vector<int>(M));
    vector<pii> cheese;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> paper[i][j];
            if (paper[i][j] == 1)
                cheese.push_back({i, j});
        }
    }

    int time = 0;
    vector<vector<int>> paper_copy = vector<vector<int>>(N, vector<int>(M));
    while (cheese.size() > 0) {
        copy(paper.begin(), paper.end(), paper_copy.begin());
        for (auto iter = cheese.begin(); iter != cheese.end();) {
            if (check_melt(iter->first, iter->second)) {
                paper_copy[iter->first][iter->second] = 0;
                iter = cheese.erase(iter);
            } else
                ++iter;
        }
        copy(paper_copy.begin(), paper_copy.end(), paper.begin());

        time += 1;
    }

    cout << time;
}
