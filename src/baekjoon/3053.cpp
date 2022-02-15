#include <iostream>
#include <cmath>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double r;
    const double pi = acos(-1);
    cin >> r;
    
    // (2^(1/2)/2*r)^2 = 2(r^2)
    cout.precision(6);
    cout << fixed <<  (pi * r * r) << "\n" << 2 * r * r << "\n";
}
