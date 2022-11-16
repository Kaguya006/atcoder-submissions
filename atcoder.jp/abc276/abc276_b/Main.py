n, m = map(int, input().split())
a = [[] for _ in range(n)]
for i in range(m):
    t, u = map(int, input().split())
    a[t - 1].append(u)
    a[u - 1].append(t)

for bridges in a:
    sorted_bridges = sorted(bridges)
    print(len(bridges), end=" ")
    print(*sorted_bridges, sep=" ")