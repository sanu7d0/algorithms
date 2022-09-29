#include <cmath>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N, count = 0;
int board[15];

bool promising(int c) {
    for (int i = 0; i < c; ++i)
        if (board[c] == board[i] || c - i == abs(board[c] - board[i]))
            return false;

    return true;
}

void nqueen(int c) {
    if (c == N) {
        count += 1;
        return;
    }

    for (int i = 0; i < N; ++i) {
        board[c] = i;
        if (promising(c))
            nqueen(c + 1);
    }
}

int main() {
    fastio;

    cin >> N;

    nqueen(0);

    cout << count;
}
