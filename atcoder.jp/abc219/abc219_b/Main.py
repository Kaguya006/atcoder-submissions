a = [input() for _ in range(3)]
t = input()

ans = ""
for c in t:
    ans += a[int(c) - 1]
print(ans)
