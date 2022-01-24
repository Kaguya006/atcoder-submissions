import sys
input = sys.stdin.readline
INF = 1000000000 + 7

n = int(input())
ans = INF
for i in range(n):
    a, p, x = map(int, input().split())
    if a < x: ans = min(ans, p)

if (ans == INF):
    print(-1)
else:
    print(ans)
