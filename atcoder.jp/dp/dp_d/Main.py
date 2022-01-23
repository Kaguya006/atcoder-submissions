import pprint
import sys
input = sys.stdin.readline

n, w = map(int, input().split())
data = [list(map(int, input().split())) for i in range(n)]

dp = [[0] * (w + 1) for i in range(n + 1)]

for i in range(1, n + 1):
    for j in range(w + 1):
        weight, value = [data[i - 1][0], data[i - 1][1]]
        add = 0
        if weight <= j:
            add += value
            if j >= weight:
                add += dp[i - 1][j - weight]
        dp[i][j] = max(dp[i - 1][j], add)
#pprint.pprint(dp)
print(dp[n][w])
