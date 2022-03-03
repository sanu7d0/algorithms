#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;

    int a, b;
    cin >> a >> b;
    while (!(a == 0 && b == 0)) {
        if (b % a == 0)
            cout << "factor\n";
        else if (a % b == 0)
            cout << "multiple\n";
        else
            cout << "neither\n";

        cin >> a >> b;
    }
}
