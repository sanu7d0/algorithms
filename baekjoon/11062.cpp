#include <algorithm>
#include <iostream>
#include <memory.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

const int INF = 100000000;
int cards[1000];
int dp[1000][1000];

int minimax(int front, int back, bool maxTurn)
{
    if (front > back)
        return 0;

    if (dp[front][back] > 0)
        return dp[front][back];

    if (maxTurn)
        return dp[front][back] =
                   max(cards[front] + minimax(front + 1, back, false), cards[back] + minimax(front, back - 1, false));
    else
        return dp[front][back] = min(minimax(front + 1, back, true), minimax(front, back - 1, true));
}

int main()
{
    fastio;

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        for (int i = 0; i < N; ++i)
            cin >> cards[i];

        memset(dp, 0, sizeof(dp));
        minimax(0, N - 1, true);
        cout << dp[0][N - 1] << "\n";
    }
}
