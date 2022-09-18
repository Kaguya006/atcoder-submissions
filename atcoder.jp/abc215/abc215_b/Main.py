n = int(input())

ans = -1
for i in range(100):
    x = pow(2, i)
    if x > n:
        break
    ans = max(ans, i)

print(ans)
