from queue import PriorityQueue

N, M = map(int, input().split())
adj = [[] for i in range(N + 1)]
dist = [-1] * (N + 1)

for i in range(M):
    a, b, c = map(int, input().split())

    adj[a].append((b, c))
    adj[b].append((a, c))

# dijkstra
pq = PriorityQueue()
pq.put((0, 1))
dist[1] = 0

while not pq.empty():
    cur = pq.get()[1]

    for v in adj[cur]:
        next = v[0]
        cost = v[1]
        if dist[next] < 0 or dist[next] > dist[cur] + cost:
            dist[next] = dist[cur] + cost
            pq.put((dist[next], next))

print(dist[N])
