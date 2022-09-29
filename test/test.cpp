#include <algorithm>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
    fastio;

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cout << 3 * (i / 3) << " " << i + 3 * (i / 3) << "\n";
    }
}
