#include <iostream>
#include <string>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

bool is_doom_number(int n) {
    int continuity = 0;
    for (auto &ch : to_string(n)) {
        if (ch == '6') {
            continuity += 1;
            if (continuity == 3)
                return true;
        } else {
            continuity = 0;
        }
    }

    return false;
}

int main() {
    fastio;

    int N, n = 665, count = 0;

    cin >> N;

    while (count < N) {
        n++;
        if (is_doom_number(n))
            count += 1;
    }

    cout << n;
}
