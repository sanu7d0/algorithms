#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
    fastio;

    int T;
    string input;

    cin >> T;
    bool vps;
    while (T--)
    {
        stack<char> s;
        vps = true;
        cin >> input;

        for (char c : input)
        {
            if (c == '(')
                s.push(c);
            else
            {
                if (s.empty() || s.top() != '(')
                {
                    vps = false;
                    break;
                }
                else
                {
                    s.pop();
                }
            }
        }
        if (!s.empty())
            vps = false;

        cout << (vps ? "YES" : "NO") << "\n";
    }
}
