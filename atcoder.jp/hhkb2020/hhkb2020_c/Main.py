from inspect import currentframe

a = [0] * 1000000
n = int(input())
p = list(map(int, input().split()))

current = 0
ans = []
for x in p:
    a[x] = 1

    while a[current] != 0:
        current += 1
    print(current)
