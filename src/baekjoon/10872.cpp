#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 1 || n == 0) return 1;
    return n * factorial(n-1);
}

int main() {
    freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    cout << factorial(N) << "\n";
}
