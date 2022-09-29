#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int rendered[1001];

int gcd(int a, int b) {
    int tmp;
    while (b) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

void render(int n) {
    int x = n;
    int count = 0;
    for (int y = 1; y < n; y++) {
        // check (x,y)
        if (gcd(x, y) == 1)
            count += 1;
    }

    rendered[n] = rendered[n - 1] + 2 * count;
}

int main() {
    fastio;

    int C, N;
    cin >> C;

    rendered[1] = 3;
    for (int i = 2; i <= 1000; i++) {
        render(i);
    }

    while (C--) {
        cin >> N;
        cout << rendered[N] << "\n";
    }
}
