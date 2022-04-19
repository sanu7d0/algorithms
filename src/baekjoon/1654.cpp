#include "stdio.h"
#include <algorithm>
#include <iostream>
#include <vector>

using uint64 = unsigned long long;
using namespace std;

int main()
{
    int K, N;
    scanf("%d %d", &K, &N);
    vector<uint64> nums(K);

    for (int i = 0; i < K; ++i)
        scanf("%d", &nums[i]);

    uint64 left, right, result;
    left = 1;
    right = *std::max_element(nums.begin(), nums.end());
    result = 0;

    while (left <= right) {
        uint64 mid = left + (right - left) / 2;

        uint64 total = 0;
        for (uint64 i : nums)
            total += i / mid;
        // printf("mid, total : %llu, %llu\n", mid, total);

        if (total >= N) {
            left = mid + 1;
            result = mid;
        } else
            right = mid - 1;
    }

    printf("%llu", result);
}
