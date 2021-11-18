n = int(input())
a = list(map(int, input().split()))

t = [0] * n

for i in range(len(a)):
    t[a[i] - 1] = i + 1

print(*t)
