#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
    fastio;

    int A;
    cin >> A;
    for (int n = 1; n <= A; ++n)
    {
        if (30 % (n + 1) == 0)
            cout << n << "\n";
    }
}
