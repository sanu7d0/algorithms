#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

bool board[100][100];

void flip(int a, int b)
{
    for (int i = 0; i <= a; ++i)
        for (int j = 0; j <= b; ++j)
            board[i][j] = !board[i][j];
}

int main()
{
    fastio;

    int N, M;
    cin >> N >> M;
    cin.ignore();

    for (int i = 0; i < N; ++i) {
        string input;
        getline(cin, input);

        for (int j = 0; j < M; ++j)
            board[i][j] = (input[j] == '0' ? true : false);
    }

    int count = 0;
    // Start from bottom-right
    int i = N - 1, j = M - 1;
    while (i >= 0 && j >= 0) {
        // horizontal
        for (int k = j; k >= 0; --k) {
            if (!board[i][k]) {
                flip(i, k);
                count++;
            }
        }

        // vertical
        for (int k = i; k >= 0; --k) {
            if (!board[k][j]) {
                flip(k, j);
                count++;
            }
        }

        i--;
        j--;
    }

    cout << count << "\n";
}
