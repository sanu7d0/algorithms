#include <stdio.h>

#define Abs(x) (((x) < 0) ? -(x) : (x))
#define INF 2147483647

void merge(int* A, int n, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1 + 1];
    int R[n2 + 1];

    int i, j;
    for (i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (j = 0; j < n2; j++)
        R[j] = A[q + j + 1];
    L[n1] = INF;
    R[n2] = INF;

    i = j = 0;
    int k;
    for (k = p; k <= r; k++) {
        if (L[i] <= R[j])
            A[k] = L[i++];
        else
            A[k] = R[j++];
    }
}

void merge_sort(int* A, int n, int p, int r)
{
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(A, n, p, q);
        merge_sort(A, n, q + 1, r);
        merge(A, n, p, q, r);
    }
}

void solve(int* A, int n)
{
    merge_sort(A, n, 0, n - 1);

    int k = A[n / 2];

    unsigned long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += (unsigned long long)Abs(A[i] - k);
    printf("%llu\n", sum);
}

int main()
{
    int a1[5] = { 1, 3, 2, 6, 7 };
    solve(a1, 5);
    int a2[1] = { 1 };
    solve(a2, 1);
    int a3[7] = { 3, 0, 1000000000, 1000000000, 1000000001, 2000000002, 2000000001 };
    solve(a3, 7);
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
