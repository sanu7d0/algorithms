#include <iostream>
#include <cmath>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    if (N == 1) return 0;

    for (int i = 2; i < sqrt(N)+1; i++)
    {
        while (N % i == 0)
        {
            cout << i << "\n";
            N /= i;
        }
    }
    if (N != 1) cout << N;
}
