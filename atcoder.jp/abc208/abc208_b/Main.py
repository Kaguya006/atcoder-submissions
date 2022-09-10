from math import factorial

p = int(input())
a = reversed([factorial(i) for i in range(1, 10 + 1)])
ans = 0

for x in a:
    if p // x > 0:
        ans += p // x
        p %= x

print(ans)
