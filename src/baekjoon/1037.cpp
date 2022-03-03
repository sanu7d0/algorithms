#include <algorithm>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;

    int n = 1, D, d, before = 1;
    cin >> D;

    for (int i = 0; i < D; ++i) {
        cin >> d;
        if (n == d) {
            n *= 2;
        } else if (n % d == 0)
            continue;
        else
            n *= d;
    }

    cout << n;
}
