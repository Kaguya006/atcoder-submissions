import sys
input = sys.stdin.readline


h, w, x, y = map(int, input().split())
g = [input().strip() for _ in range(h)]

ans = 0

cnt = 0
left = True
for j in range(w):
    if left and j == y - 1:
        cnt += 1
        left = False
    elif g[x - 1][j] == '#':
        if not left:
            break
        else:
            cnt = 0
    else:
        cnt += 1
ans += cnt
cnt = 0

above = True
for i in range(h):
    if above and i == x - 1:
        above = False
    elif g[i][y - 1] == '#':
        if not above:
            break
        else:
            cnt = 0
    else:
        cnt += 1

print(ans + cnt)
