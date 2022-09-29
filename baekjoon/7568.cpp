#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;

    int N, x, y;
    vector<pair<int, int>> body;
    vector<int> rank;

    cin >> N;
    rank = vector<int>(N, 1);
    while (N--) {
        cin >> x >> y;
        body.push_back(make_pair(x, y));
    }

    for (int i = 0; i < body.size(); ++i) {
        for (int j = 0; j < body.size(); ++j) {
            if (body[i].first > body[j].first &&
                body[i].second > body[j].second) {
                rank[j] += 1;
            }
        }
    }

    for (auto r : rank) {
        cout << r << " ";
    }
}
