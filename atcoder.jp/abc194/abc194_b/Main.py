import sys
input = sys.stdin.readline
INF = 1000000000 + 7

n = int(input())
a = []
b = []

for i in range(n):
    t, tt = map(int, input().split())
    a.append(t)
    b.append(tt)

ans = INF
for i in range(n):
    for j in range(n):
        if i == j:
            ans = min(ans, a[i] + b[j])
        else:
            ans = min(ans, max(a[i], b[j]))
print(ans)
