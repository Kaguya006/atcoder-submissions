s, t = map(int, input().split())

ans = 0
for i in range(101):
    for j in range(101):
        for k in range(101):
            if i + j + k <= s:
                if i * j * k <= t:
                    ans += 1
print(ans)
