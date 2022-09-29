#include <iostream>
#include <stack>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
    fastio;

    int n;
    cin >> n;

    stack<int> src;
    stack<int> dst;
    {
        int x;
        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            dst.push(x);
        }
    }
}
