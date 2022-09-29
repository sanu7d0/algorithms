#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n[3];
    while (true) {
        cin >> n[0] >> n[1] >> n[2];
        if (!(n[0] + n[1] + n[2])) break;

        sort(n, n+3);
        cout << ((n[2]*n[2] - n[1]*n[1] - n[0]*n[0] == 0) ? "right" : "wrong") << "\n";
    }
}
