N, M = map(int, input().split())
G = [[False] * (N + 1) for _ in range(N + 1)]

for i in range(M):
    u, v = map(int, input().split())
    G[u][v] = True
    G[v][u] = True

ans = 0
for i in range(1, N + 1):
    for j in range(i + 1, N + 1):
        for k in range(j + 1, N + 1):
            if G[i][j] and G[j][k] and G[k][i]:
                ans += 1

print(ans)
