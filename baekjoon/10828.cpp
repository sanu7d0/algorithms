#include <iostream>
#include <stack>
#include <string>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
    fastio;

    int N, x;
    string cmd;
    stack<int> s;

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> cmd;
        if (cmd == "push")
        {
            cin >> x;
            s.push(x);
        }
        else if (cmd == "pop")
        {
            if (s.empty())
                cout << -1 << "\n";
            else
            {
                cout << s.top() << "\n";
                s.pop();
            }
        }
        else if (cmd == "top")
        {
            if (s.empty())
                cout << -1 << "\n";
            else
            {
                cout << s.top() << "\n";
            }
        }
        else if (cmd == "empty")
        {
            cout << (s.empty() ? 1 : 0) << "\n";
        }
        else if (cmd == "size")
        {
            cout << s.size() << "\n";
        }
    }
}
