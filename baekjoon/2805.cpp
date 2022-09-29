#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)

using uint64 = unsigned long long;
using namespace std;

void split(const string& input, const char delim, vector<uint64>& nums)
{
    stringstream ss(input);
    string tmp;

    while (getline(ss, tmp, delim))
        nums.push_back(stoull(tmp));
}

int main()
{
    int N, M;
    cin >> N >> M;
    cin.ignore();

    vector<uint64> nums;
    string input;
    getline(cin, input);
    split(input, ' ', nums);
    input.clear();

    uint64 left, right, result;
    left = 0;
    right = *std::max_element(nums.begin(), nums.end());
    result = 0;

    while (left <= right) {
        uint64 mid = left + (right - left) / 2;

        uint64 total = 0;
        for (uint64 i : nums)
            total += (i >= mid ? i - mid : 0);
        // printf("mid, total : %llu, %llu\n", mid, total);

        if (total >= M) {
            left = mid + 1;
            result = (mid > result ? mid : result);
        } else
            right = mid - 1;
    }

    cout << result;
}
