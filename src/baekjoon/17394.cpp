#include "memory.h"
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define MAX_NUM 1'000'000

bool prime[MAX_NUM + 1];
int A, B, N;

bool get_primes(int a, int b)
{
    bool prime_exist = false;
    for (int i = 2; i <= b; ++i) {
        if (!prime[i])
            continue;
        else if (a <= i && prime[i])
            prime_exist = true;

        for (int j = 2 * i; j <= b; j += i)
            prime[j] = false;
    }
    return prime_exist;
}

int bfs(int root)
{
    queue<pair<int, int>> q;
    vector<bool> visited = vector<bool>(MAX_NUM + 1, false);
    q.push({ root, 0 });
    visited[root] = true;

    while (!q.empty()) {
        int cur = q.front().first;
        int hop = q.front().second;
        q.pop();

        if (A <= cur && cur <= B && prime[cur])
            return hop;

        if (cur >= A && !visited[cur / 3]) {
            visited[cur / 3] = true;
            q.push({ cur / 3, hop + 1 });
        }
        if (cur >= A && !visited[cur / 2]) {
            visited[cur / 2] = true;
            q.push({ cur / 2, hop + 1 });
        }
        if (cur + 1 <= B && !visited[cur + 1]) {
            visited[cur + 1] = true;
            q.push({ cur + 1, hop + 1 });
        }
        if (cur >= A && !visited[cur - 1]) {
            visited[cur - 1] = true;
            q.push({ cur - 1, hop + 1 });
        }
    }

    return -444;
}

int main()
{
    fastio;

    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;

    int T;
    cin >> T;
    while (T--) {
        cin >> N >> A >> B;
        if (!get_primes(A, B)) {
            cout << "-1\n";
            continue;
        }

        cout << bfs(N) << "\n";
    }
}
