#include <algorithm>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

vector<vector<int>> adj;

constexpr int c2i(char c)
{
    return (int)(c - 'A') + 1;
}
constexpr char i2c(int i)
{
    return (char)i + 'A' - 1;
}

void preorder(int node)
{
    cout << i2c(node);
    if (adj[node][0])
        preorder(adj[node][0]);
    if (adj[node][1])
        preorder(adj[node][1]);
}

void inorder(int node)
{
    if (adj[node][0])
        inorder(adj[node][0]);
    cout << i2c(node);
    if (adj[node][1])
        inorder(adj[node][1]);
}

void postorder(int node)
{
    if (adj[node][0])
        postorder(adj[node][0]);
    if (adj[node][1])
        postorder(adj[node][1]);
    cout << i2c(node);
}

int main()
{
    fastio;

    int N;
    char node, left, right;

    cin >> N;
    adj = vector<vector<int>>(27);

    for (int i = 0; i < N; ++i)
    {
        cin >> node >> left >> right;
        adj[c2i(node)].push_back(left == '.' ? 0 : c2i(left));
        adj[c2i(node)].push_back(right == '.' ? 0 : c2i(right));
    }

    preorder(1);
    cout << "\n";
    inorder(1);
    cout << "\n";
    postorder(1);
    cout << "\n";
}
