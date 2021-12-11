import itertools 

n = int(input())
a = list(map(int, input().split()))
x = int(input())
ac = list(itertools.accumulate(a))
last = ac[-1]

ans = (x // last) * n
t = (x // last) * last

i = 0
while(True):
    t += a[i]
    ans += 1
    i += 1

    if t > x:
        break

print(ans)
