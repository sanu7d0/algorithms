#include <iostream>
#include <stack>
#include <string>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
    fastio;

    string input;
    bool vps;

    getline(cin, input);
    while (input != ".")
    {
        stack<char> s;
        vps = true;

        for (char c : input)
        {
            if (c == '(' || c == '[')
                s.push(c);
            else if (c == ')')
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
            else if (c == ']')
            {
                if (s.empty() || s.top() != '[')
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

        cout << (vps ? "yes" : "no") << "\n";
        getline(cin, input);
    }
}
