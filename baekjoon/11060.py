N = int(input())
maze = list(map(int, input().split()))

jumps = [-1] * N
jumps[0] = 0

stack = [0]
while stack:
    cur = stack.pop()
    for next in range(cur + 1, min(cur + maze[cur] + 1, N)):
        if jumps[next] < 0 or jumps[cur] + 1 < jumps[next]:
            jumps[next] = jumps[cur] + 1
            stack.append(next)

print(jumps[N - 1])
