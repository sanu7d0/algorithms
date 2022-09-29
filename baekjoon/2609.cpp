#include <cmath>
#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    fastio;

    int a, b;
    cin >> a >> b;

    int d = gcd(max(a, b), min(a, b));
    cout << d << "\n" << a * b / d;
}
