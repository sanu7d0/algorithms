N = int(input())
A = [int(input()) for i in range(N)]
dp = [0] * N

dp[0] = A[0]
dp[1] = A[0] + A[1]
dp[2] = max(A[1] + A[2], A[0] + A[2])

for i in range(3, N):
    dp[i] = max(dp[i - 3] + A[i - 1] + A[i], dp[i - 2] + A[i])

print(dp[N - 1])
