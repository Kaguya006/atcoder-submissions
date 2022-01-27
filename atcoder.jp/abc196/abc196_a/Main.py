a, b = map(int, input().split())
c, d = map(int, input().split())

t = max(a, b)
tt = min(c, d)

print(t - tt)
