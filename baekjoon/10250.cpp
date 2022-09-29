#include <iostream>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T, h, w, n;
    cin >> T;
    while (T--) {
        cin >> h >> w >> n;

        string room = to_string((n-1)/h+1);
        if ((n-1)/h+1 < 10)
            room.insert(0, "0");
        cout << (n-1) % h + 1 << room << "\n";
    }
}
