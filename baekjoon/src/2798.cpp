#include <cmath>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;

    int N, M, n;
    vector<int> nums;

    cin >> N >> M;
    while (N--) {
        cin >> n;
        nums.push_back(n);
    }

    int ans = 0, sum;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                sum = nums[i] + nums[j] + nums[k];
                if (sum <= M) {
                    ans = max(ans, sum);
                }
            }
        }
    }
    cout << ans << endl;
}
