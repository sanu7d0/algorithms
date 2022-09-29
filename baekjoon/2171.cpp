#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
    fastio;

    int N;
    cin >> N;
    if (N < 4) {
        cout << 0 << "\n";
        return 0;
    }

    unordered_map<int, vector<int>> x2y;

    for (int x, y, i = 0; i < N; ++i) {
        cin >> x >> y;
        x2y[x].push_back(y);
    }

    int count = 0;
    for (auto iter1 = x2y.begin(); iter1 != x2y.end();) {
        const int x1 = iter1->first;
        const vector<int>& yList1 = iter1->second;

        ++iter1;
        for (auto iter2 = iter1; iter2 != x2y.end(); ++iter2) {
            const int x2 = iter2->first;
            const vector<int>& yList2 = iter2->second;

            if (yList1.size() < 2 || yList2.size() < 2) // No line
                continue;

            for (int i = 0; i < yList1.size() - 1; ++i) {
                for (int j = i + 1; j < yList1.size(); ++j) {
                    if (find(yList2.begin(), yList2.end(), yList1[i]) != yList2.end()
                        && find(yList2.begin(), yList2.end(), yList1[j]) != yList2.end()) {
                        count++;
                    }
                }
            }
        }
    }

    cout << count;
}
