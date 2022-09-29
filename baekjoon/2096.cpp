#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;

    int N;
    cin >> N;

    int x0, x1, x2;
    cin >> x0 >> x1 >> x2;

    int min_point[3] = {x0, x1, x2};
    int max_point[3] = {x0, x1, x2};
    int tmp0, tmp1, tmp2;

    for (int i = 1; i < N; i++) {
        cin >> x0 >> x1 >> x2;

        tmp0 = x0 + min(min_point[0], min_point[1]);
        tmp1 = x1 + min({min_point[0], min_point[1], min_point[2]});
        tmp2 = x2 + min(min_point[1], min_point[2]);
        min_point[0] = tmp0;
        min_point[1] = tmp1;
        min_point[2] = tmp2;

        tmp0 = x0 + max(max_point[0], max_point[1]);
        tmp1 = x1 + max({max_point[0], max_point[1], max_point[2]});
        tmp2 = x2 + max(max_point[1], max_point[2]);
        max_point[0] = tmp0;
        max_point[1] = tmp1;
        max_point[2] = tmp2;
    }

    cout << *max_element(max_point, max_point + 3) << " "
         << *min_element(min_point, min_point + 3);
}
