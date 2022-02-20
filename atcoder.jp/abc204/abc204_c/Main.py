import sys
sys.setrecursionlimit(10**7)

ans = 0

def dfs(graph, v, seen):
    global ans
    seen[v] = True
    for next_v in graph[v]:
        if seen[next_v]: continue
        ans += 1
        dfs(graph, next_v, seen)

n, m = map(int, input().split())
g = [[] for _ in range(n)]
s = [False] * n
for i in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    g[a].append(b)

for i in range(n):
    dfs(g, i, s[:])

print(ans + n)
