#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T, n, a, b, diff;
    vector<bool> primes(10001, true);
    primes[1] = false;
    for (int i = 2; i <= 10000; i++) {
        if (!primes[i]) continue;
        for (int j = 2*i; j <= 10000; j += i) {
            primes[j] = false;
        }
    }

    cin >> T;
    while (T--) {
        cin >> n;
        diff = 10000;
        // iterate reversely to find smallest gap
        for (int i = n/2; i >= 0; i--)
        {
            a = i;
            b = n - i;
            if (primes[a] && primes[b])
            {
                cout << a << " " << b << "\n";
                break;
            }
        }
    }
}
