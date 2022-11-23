N = int(input())
A = list(map(int, input().split()))
even = list()
odd = list()
for a in A:
    if a % 2 == 0:
        even.append(a)
    else:
        odd.append(a)
even.sort()
odd.sort()

ans = -1
for x in A:
    if x % 2 == 0:
        if even[-1] != x:
            ans = max(ans, x + even[-1])
        elif len(even) > 1:
            ans = max(ans, x + even[-2])
    else:
        if odd[-1] != x:
            ans = max(ans, x + odd[-1])
        elif len(odd) > 1:
            ans = max(ans, x + odd[-2])
print(ans)
