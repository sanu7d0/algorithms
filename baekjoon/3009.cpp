#include <iostream>
#include <map>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int x, y;
    map<pair<int,int>, int> m;
    pair<int, int> xp{0, 0}, yp{0, 0};
    for (int i=0; i < 3; i++)
    {
        cin >> x >> y;
        xp.first = x;
        yp.second = y;
        
        if (m.count(xp)) {
            m[xp] -= 1;
        } else {
            m[xp] = 1;
        }
        if (m.count(yp)) {
            m[yp] -= 1;
        } else {
            m[yp] = 1;
        }
    }

    x = y = 0;
    for (const auto& [key, value] : m) {
        x += key.first * value;
        y += key.second * value;
    }

    cout << x << " " << y << endl;
}
