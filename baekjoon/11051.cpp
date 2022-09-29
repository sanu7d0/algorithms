#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
typedef long long ll;

int memoization[1001][1001];

int main()
{
    fastio;

    ll N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 0; j <= N; ++j)
        {
            if (i == j || j == 0)
                memoization[i][j] = 1;
            else
                memoization[i][j] = (memoization[i - 1][j] + memoization[i - 1][j - 1]) % 10007;
        }
    }
    cout << memoization[N][K];
}
