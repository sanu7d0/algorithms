#include <iostream>
using namespace std;

typedef long long ll;

const ll MOD = 15746;

int main() {
    int d[1000001];
    d[1] = 1;
    d[2] = 2;

    int n;
    cin >> n;

    for (int i = 3; i <= n; ++i) {
        d[i] = d[i - 1] + d[i - 2];
        d[i] %= MOD;
    }

    cout << d[n];
}
