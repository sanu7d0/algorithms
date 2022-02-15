#include <algorithm>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

void selection_sort(vector<int> *v) {
    for (int i = 0; i < v->size() - 1; ++i) {
        int tmp = i;
        for (int j = i + 1; j < v->size(); ++j) {
            if (v->at(tmp) >= v->at(j))
                tmp = j;
        }

        int swap = v->at(i);
        v->at(i) = v->at(tmp);
        v->at(tmp) = swap;
    }
}

void quick_sort(vector<int> *v) {}

int main() {
    fastio;

    int N, n;
    vector<int> v;
    cin >> N;
    while (N--) {
        cin >> n;
        v.push_back(n);
    }

    selection_sort(&v);

    for (auto &i : v) {
        cout << i << "\n";
    }
}
