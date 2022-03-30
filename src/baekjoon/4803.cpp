#include "memory.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

struct UnionFind
{
    int parent[501];
    bool tree[501];

    void Clear(int n)
    {
        iota(parent + 1, parent + n + 1, 1);
        memset(tree + 1, true, sizeof(bool) * n);
    }

    int Find(int x)
    {
        return x == parent[x] ? x : parent[x] = Find(parent[x]);
    }

    void Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);
        a == b ? tree[a] = false : parent[b] = a;
        tree[a] |= tree[b];
    }
};

int main()
{
    fastio;

    UnionFind uf;
    for (int n, m, i = 1; cin >> n >> m && (n || m); i++)
    {
        int cnt = 0;
        uf.Clear(n);
        for (int a, b; m > 0; m--)
        {
            cin >> a >> b;
            uf.Union(a, b);
        }
        for (int i = 1; i <= n; i++)
            if (i == uf.Find(i) && uf.tree[i])
                cnt += 1;

        cout << "Case " << i << ": ";
        if (cnt == 0)
            cout << "No trees.\n";
        else if (cnt == 1)
            cout << "There is one tree.\n";
        else
            cout << "A forest of " << cnt << " trees.\n";
    }
}
