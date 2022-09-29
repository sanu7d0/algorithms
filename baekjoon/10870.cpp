#include <iostream>
using namespace std;

int fibo(int n)
{
    if (n == 0) return 0;
    else if (n == 1) return 1;
    return fibo(n-2) + fibo(n-1);
}

int main() {
    freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    cout << fibo(N) << "\n";
}
