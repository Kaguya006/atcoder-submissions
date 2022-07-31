import math

a, b, c, d = map(int, input().split())
t = b - c * d
if t == 0:
    print(-1)
    exit()

ans = math.ceil(-a / t)

if ans < 0:
    print(-1)
else:
    print(ans)