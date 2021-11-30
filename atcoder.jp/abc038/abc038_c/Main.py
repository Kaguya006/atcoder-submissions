n = int(input())
a = list(map(int, input().split()))

right = 0
ans = 0
for left in range(n + 1):
    while right + 1 < n and a[right] < a[right + 1]:
        right += 1

    if right == left: 
        right += 1
        ans += 1
    else:
        ans += right - left + 1

    if right == n:
        break

print(ans)
