N = int(input())

hexa = [1]
while hexa[-1] <= N:
    num = hexa[-1] + 6 * len(hexa) - (2 * len(hexa) - 1)
    if num > N:
        break
    hexa.append(num)

dp = [1000000] * 1000001
dp[0] = 0
dp[1] = 1
dp[11] = 6
dp[26] = 6
dp[130] = 5
dp[146858] = 4

if N > 146858:
    dp[N] = 3
else:
    for i in range(2, N + 1):
        print(i)
        for h in hexa:
            if h > i:
                break
            dp[i] = min(dp[i], 1 + dp[i - h])

print(dp[N])
