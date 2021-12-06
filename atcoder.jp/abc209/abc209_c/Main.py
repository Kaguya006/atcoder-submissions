import collections
MOD = 1000000000 + 7

n = int(input())
c = list(map(int, input().split()))
counter = collections.Counter(c)
sorted_counter = sorted(counter.items(), key = lambda x:x[0])

current = 0
ans = 1
for x in sorted_counter:
    t = x[0] - current
    if t < 1 or t < x[1]:
        ans = 0
        break
    else:
        for i in range(x[1]):
            ans *= (t - i)
            ans %= MOD
        current += x[1]
print(ans)
