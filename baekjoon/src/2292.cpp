#include <iostream>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long N;
    cin >> N;
    
    int i = 1;
    // 1 + n(n-1)6 / 2
    while (1 + i*(i-1)*3 < N)
    {
        i++;
    }

    cout << i << "\n";
}
