import sys

sys.setrecursionlimit(10**6)
from collections import defaultdict

ans = 1
d = defaultdict(list)
seen = set()


def dfs(d, current):
    seen.add(current)

    global ans
    ans = max(ans, current)
    if current in d:
        for next in d[current]:
            if next in seen:
                continue
            dfs(d, next)
    return


n = int(input())
for i in range(n):
    a, b = map(int, input().split())
    d[a].append(b)
    d[b].append(a)

dfs(d, 1)
print(ans)