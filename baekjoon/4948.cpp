#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, count;
    vector<bool> primes(123456*2 + 1, true);
    while (true) {
        cin >> n;
        if (n == 0) break;

        count = 0;
        for (int i = 2; i <= 2*n; i++)
        {
            if (!primes[i]) continue;
            for (int j = i+i; j <= 2*n; j += i)
            {
                primes[j] = false;
            }
        }

        for (int i = n+1; i <= 2*n; i++)
        {
            if (primes[i])
                count++;
        }
        cout << count << "\n";
    }
}
