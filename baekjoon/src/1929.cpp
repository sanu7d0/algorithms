#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    
    int M, N;
    cin >> M >> N;

    vector<bool> primes(N+1, true);
    primes[1] = false;

    for (int i = 2; i <= N; i++)
    {
        if (!primes[i]) continue;
        for (int j = i+i; j <= N; j += i)
        {
            primes[j] = false;
        }
    }

    for (int i = M; i <= N; i++)
    {
        if (primes[i])
            cout << i << "\n";
    }

    return 0;
}
