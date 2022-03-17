#include <iostream>
#include <string>
#include <unordered_map>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;

    int T, n;
    cin >> T;
    while (T--) {
        string cloth, part;
        unordered_map<string, uint> m;

        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> cloth >> part;
            if (m.find("part") != m.end())
                m.insert({part, 0});
            else
                m[part] += 1;
        }

        int ans = 1;
        for (const auto &[key, val] : m) {
            ans *= (val + 1);
        }
        ans -= 1;
        cout << ans << "\n";
    }
}
