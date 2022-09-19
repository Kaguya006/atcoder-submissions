n, p = map(int, input().split())
ans = 0

a = list(map(int, input().split()))
for x in a:
    if x < p:
        ans += 1

print(ans)
