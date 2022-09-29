#include <iostream>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    bool possible = false;
    int x = N / 2;
    // (N - 2x) / 3 = ans, x must be minimum
    // ans - x = (N - 5x) / 3 >= 0 -> N - 5x >= 0
    while (x >= 0)
    {
        if ((N - 2*x) % 3 == 0 && N - 2*x != 0 && N - 5*x >= 0)
        {
            cout << (N -2 * x) /3 << "\n";
            possible = true;
            break;
        }
        x--;
    }

    if (!possible)
        cout << -1 << "\n";
}
