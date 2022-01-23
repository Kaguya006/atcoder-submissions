n, k = map(int, input().split())
h = list(map(int, input().split()))
costs = [10000000000] * n
costs[0] = 0

for i in range(n - 1):
    for j in range(k):
        pos = i + j + 1
        if pos < n:
            costs[pos] = min(costs[i] + abs(h[i] - h[pos]), costs[pos])
            
print(costs[n - 1])
