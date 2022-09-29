#include <algorithm>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

struct Time {
    int begin;
    int end;
};

bool cmp(Time a, Time b) {
    if (a.end == b.end)
        return a.begin < b.begin;
    else
        return a.end < b.end;
}

int main() {
    fastio;

    int N;
    vector<Time> v;

    cin >> N;
    v = vector<Time>(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i].begin >> v[i].end;
    }

    sort(v.begin(), v.end(), cmp);

    int count = 0, end = 0;
    for (auto iter = v.begin(); iter != v.end(); ++iter) {
        if (end <= iter->begin) {
            end = iter->end;
            count += 1;
        }
    }
    cout << count;
}
