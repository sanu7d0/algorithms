#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    if (n == 1) return false;

    for (int i = 2; i < (int)sqrt(n) + 1; i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m, n, sum = 0, minimum = 10000;
    cin >> m >> n;

    for (int i = m; i <= n; i++) {
        if (isPrime(i)) {
            sum += i;
            minimum = min(minimum, i);
        }
    }

    if (sum) {
        cout << sum << "\n" << minimum << "\n";
    } else {
        cout << -1 << "\n";
    }
}
