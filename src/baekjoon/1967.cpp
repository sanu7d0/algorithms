#include <cmath>
#include <iostream>
#include <stack>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n;
vector<vector<pair<int, int>>> adj;

pair<int, int> dfs(int root)
{
    vector<bool> visited = vector<bool>(n + 1, false);
    stack<pair<int, int>> s;
    s.emplace(root, 0);

    pair<int, int> res = {0, 0};
    int u, c;
    while (!s.empty())
    {
        u = s.top().first;
        c = s.top().second;
        s.pop();

        if (!visited[u])
            visited[u] = true;

        int v_count = 0;
        for (auto vc : adj[u])
        {
            if (!visited[vc.first])
            {
                s.emplace(vc.first, vc.second + c);
                v_count++;
            }
        }
        // Reached leaf
        if (v_count == 0 && res.second < c)
        {
            res.first = u;
            res.second = c;
        }
    }

    return res;
}

int main()
{
    fastio;
    cin >> n;
    adj = vector<vector<pair<int, int>>>(n + 1);

    int u, v, c;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    int x = dfs(1).first;
    cout << dfs(x).second;
}
