#include <iostream>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    int dist[4] = {w, w-x, y, h-y};

    cout << min(min(x, w-x), min(y, h-y));
}
