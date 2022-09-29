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

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int a, b;
        cin >> a >> b;
        cout << a * b / gcd(a, b) << "\n";
    }
}
