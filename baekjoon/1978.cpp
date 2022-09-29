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
    
    int N, num, count = 0;
    cin >> N;
    while (N--) {
        cin >> num;
        count += isPrime(num) ? 1 : 0;
    }

    cout << count << "\n";
}
