#include <algorithm>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N, M;
vector<int> v;
int memo[51][1001];

int recursive(int i, int vol)
{
    if (vol < 0 || vol > M || memo[i][vol] == 1)
        return -1;

    if (i == N - 1)
        return vol;

    memo[i][vol] = 1;
    return max(recursive(i + 1, vol + v[i + 1]), recursive(i + 1, vol - v[i + 1]));
}

int main()
{
    fastio;

    int S;
    cin >> N >> S >> M;

    v = vector<int>(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i];

    cout << max(recursive(0, S + v[0]), recursive(0, S - v[0])) << "\n";
}
