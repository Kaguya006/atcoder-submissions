N = int(input())
P = list(map(int, input().split()))

d = dict()
d[1] = 0
for i in range(1, N):
    p = P[i - 1]
    d[i + 1] = p

current = N
ans = 0
while d[current] != 0:
    current = d[current]
    ans += 1

print(ans)
