#include <iostream>
#include <map>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;

    int T, k;
    string w;

    cin >> T;
    while (T--) {
        cin >> w >> k;

        // pair : index, occurence
        map<char, pair<int, int>> m;

        for (int i = 0; i < w.length(); i++) {
            if (m.find(w[i]) != m.end()) {

                m
            } else {
                m.insert({w[i], {i, 0}});
            }
        }

        cout << 0 << "\n";
    }
}
