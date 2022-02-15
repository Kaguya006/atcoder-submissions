n = int(input())
a = []
b = []
c = []

for _ in range(n):
    t, tt, ttt = map(int, input().split())
    a.append(t)
    b.append(tt)
    c.append(ttt)


dp = [[0] * 3 for _ in range(n + 1)]

for i in range(1, n + 1):
    for j in range(3):
        if j == 0:
            dp[i][j] = max(dp[i - 1][1], dp[i - 1][2]) + a[i - 1]
        if j == 1:
            dp[i][j] = max(dp[i - 1][0], dp[i - 1][2]) + b[i - 1]
        if j == 2:
            dp[i][j] = max(dp[i - 1][0], dp[i - 1][1]) + c[i - 1]

ans = -1
for i in range(3):
    ans = max(ans, dp[n][i])

print(ans)
