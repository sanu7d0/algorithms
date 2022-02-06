#include <iostream>
#include <cmath>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T, x1,y1,r1,x2,y2,r2,cnt;
    double d;
    cin >> T;
    while (T--) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        d = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));

        if (d == 0 && r1 == r2) cnt = -1;
        else if (d+min(r1,r2) < max(r1, r2)) cnt = 0;
        else if (d+min(r1,r2) == max(r1, r2)) cnt = 1;
        else if (d < r1 + r2) cnt = 2;
        else if (d == r1 + r2) cnt = 1;
        else cnt = 0;
        cout << cnt << "\n";
    }
}

