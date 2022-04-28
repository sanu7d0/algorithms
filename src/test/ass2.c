#include <stdio.h>

#define abs(x) (((x) < 0) ? -(x) : (x))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
typedef unsigned long long u64;

void solve(int* A, int n)
{
    int max_elem = 0;
    u64 sum_array = 0llu;
    for (int i = 0; i < n; i++) {
        max_elem = max(max_elem, A[i]);
        sum_array += (u64)A[i];
    }

    // ! Parametric Search not work
    /*int left = 1, right = max_elem;
    u64 ans = sum_array;
    while (left <= right) {
        int mid = (left + right) / 2;

        u64 sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (u64)(abs(A[i] - mid));
        }

        if (sum < ans) {
            printf("%d ", mid);
            ans = sum;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    printf("%llu\n", ans);*/
}

int main()
{
    // int T;
    // scanf("%d", &T);
    // while (T--) {

    //     printf("%d\n", 0);
    // }

    int a1[5] = { 1, 3, 2, 6, 7 };
    solve(a1, 5);
    int a2[1] = { 1 };
    solve(a2, 1);
    int a3[5] = { 1000000000, 1000000000, 1000000000, 1000000000, 1000000000 };
    solve(a3, 5);
    int a4[3] = { 1, 2, 1 };
    solve(a4, 3);
    int a5[5] = { 1, 2, 3, 4, 100 };
    solve(a5, 5);

    int a6[1000000];
    for (int i = 0; i < 1000000; i++) {
        a6[i] = i + 1;
    }
    solve(a6, 1000000);
}
