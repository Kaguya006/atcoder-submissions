n = int(input())
h = list(map(int, input().split()))
costs = [0] * n
costs[1] = abs(h[0] - h[1])

i = 2
while i < n:
    costs[i] = min(abs(h[i] - h[i - 1]) + costs[i - 1], abs(h[i] - h[i - 2]) + costs[i - 2])
    i = i + 1
print(costs[n - 1])