#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int board[9][9];
bool row_check[9][10];
bool col_check[9][10];
bool square_check[9][10];

vector<string> answers;

string capture_board()
{
    string s;
    s.reserve(90);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j)
            s += board[i][j] + '0';
        s += "\n";
    }
    return s;
}

inline int sqaure(int r, int c)
{
    return (r / 3) * 3 + c / 3;
}

void dfs(int pos)
{
    if (pos == 81) {
        answers.push_back(capture_board());
        return;
    }

    int r = pos / 9;
    int c = pos % 9;
    if (!board[r][c]) {
        for (int n = 1; n <= 9; n++) {
            if (!row_check[r][n] && !col_check[c][n] && !square_check[sqaure(r, c)][n]) {
                row_check[r][n] = col_check[c][n] = square_check[sqaure(r, c)][n] = true;
                board[r][c] = n;

                dfs(pos + 1);

                row_check[r][n] = col_check[c][n] = square_check[sqaure(r, c)][n] = false;
                board[r][c] = 0;
            }
        }
    } else {
        dfs(pos + 1);
    }
}

int main()
{
    fastio;

    for (int i = 0; i < 9; ++i) {
        string input;
        cin >> input;
        for (int j = 0; j < 9; ++j) {
            board[i][j] = input[j] - '0';
            int val = board[i][j];
            if (val) {
                row_check[i][val] = true;
                col_check[j][val] = true;
                square_check[sqaure(i, j)][val] = true;
            }
        }
    }

    dfs(0);
    sort(answers.begin(), answers.end());
    cout << answers[0];
}
