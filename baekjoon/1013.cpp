#include <iostream>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T, i;
    cin >> T;
    while (T--) {
        i = 0;
        string signal;
        cin >> signal;

        // Target pattern = (100+1+ | 01)+
        bool isPattern = true;
        int signalSize = signal.size();
        
        // NOT SOLVED
        
        cout << (isPattern ? "YES" : "NO") << "\n";
    }
}
