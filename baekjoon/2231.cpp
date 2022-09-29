#include <iostream>
#include <string>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int decompose(int n) {
    int sum = n;
    for (auto &ch : to_string(n)) {
        sum += ch - '0';
    }
    return sum;
}

int main() {
    fastio;

    int N;
    cin >> N;

    int generator = 0;
    for (int i = 1; i < N; i++) {
        if (decompose(i) == N) {
            generator = i;
            break;
        }
    }
    cout << generator << endl;
}
