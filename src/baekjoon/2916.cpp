#include <cmath>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

vector<int> myAngles;
bool possible[361] = {false};

void check_possibles(int angle) {
    angle = abs(angle) % 360;

    if (possible[angle])
        return;
    possible[angle] = true;

    for (int i = 0; i < myAngles.size(); i++) {
        check_possibles(angle + myAngles[i]);
        check_possibles(angle - myAngles[i]);
    }
}

int main() {
    fastio;

    int N, K, t;
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> t;
        myAngles.push_back(abs(t));
    }

    possible[0] = true;
    check_possibles(myAngles[0]);

    while (K--) {
        cin >> t;
        cout << (possible[abs(t) % 360] ? "YES" : "NO") << "\n";
    }
}
