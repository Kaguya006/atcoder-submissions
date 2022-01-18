n = int(input())
ab = []
for _ in range(n):
    a, b = map(int, input().split())
    ab.append((a, b))

l = [0] * n
for i in range(n):
    l[i] = ab[i][0] / ab[i][1]

t = sum(l) / 2
ans = 0

for i in range(n):
    ans += min(ab[i][0], t * ab[i][1])
    t -= min(ab[i][0] / ab[i][1], t)

print(ans)
