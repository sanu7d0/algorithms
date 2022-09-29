#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N, M;
vector<vector<char>> board;

int paint_board(int x, int y) {
    int cnt = 0;
    char target;
    for (int i = x; i < x + 8; ++i) {
        for (int j = y; j < y + 8; ++j) {
            target = (i % 2 ^ j % 2) ? 'W' : 'B';
            if (board[i][j] != target) {
                cnt += 1;
            }
        }
    }

    return min(cnt, 64 - cnt);
}

int main() {
    fastio;
    

    cin >> N >> M;
    string s;
    for (int i = 0; i < N; ++i) {
        cin >> s;
        board.push_back(vector<char>(s.begin(), s.end()));
    }

    int ans = 64;
    for (int i = 0; i <= N - 8; ++i) {
        for (int j = 0; j <= M - 8; ++j) {
            ans = min(ans, paint_board(i, j));
        }
    }

    cout << ans << endl;
}
