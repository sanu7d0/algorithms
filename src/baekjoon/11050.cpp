#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int factorial(int n)
{
    int res = 1;
    for (int i = 1; i <= n; ++i)
    {
        res *= i;
    }
    return res;
}

int binomial(int n, int k)
{
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main()
{
    fastio;

    int N, K;
    cin >> N >> K;
    cout << binomial(N, K);
}
