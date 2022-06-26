import math

n = int(input())
x = [None] * n
y = [None] * n
for i in range(n):
    t1, t2 = map(int, input().split())
    x[i], y[i] = t1, t2

t = []
for i in range(n):
    for j in range(i, n):
        if i == j:
            continue
        dx = x[i] - x[j]
        dy = y[i] - y[j]
        t.append(math.sqrt(pow(dx, 2) + pow(dy, 2)))
print(max(t))
