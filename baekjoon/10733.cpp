#include <iostream>
#include <stack>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
    fastio;

    int K, x;
    stack<int> s;

    cin >> K;
    for (int i = 0; i < K; ++i)
    {
        cin >> x;
        if (x == 0)
            s.pop();
        else
            s.push(x);
    }

    int sum = 0;
    int size = s.size();
    for (int i = 0; i < size; ++i)
    {
        sum += s.top();
        s.pop();
    }
    cout << sum << endl;
}
