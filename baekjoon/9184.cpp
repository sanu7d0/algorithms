#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int d[51][51][51] = {0};

int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;

    if (d[a][b][c] > 0)
        return d[a][b][c];

    if (a > 20 || b > 20 || c > 20) {
        int res = w(20, 20, 20);
        d[a][b][c] = res;
        return res;
    }

    if (a < b && b < c) {
        int res = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        d[a][b][c] = res;
        return res;
    } else {
        int res = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) -
                  w(a - 1, b - 1, c - 1);
        d[a][b][c] = res;
        return res;
    }
}

int main() {
    fastio;

    int a, b, c;
    cin >> a >> b >> c;
    while (!(a == -1 && b == -1 && c == -1)) {
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c)
             << "\n";
        cin >> a >> b >> c;
    }
}
