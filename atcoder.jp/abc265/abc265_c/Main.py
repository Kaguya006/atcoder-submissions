H, W = map(int, input().split())
G = [list(input()) for _ in range(H)]
visited = [[False] * W for _ in range(H)]

ans = (-1, -1)
current = (0, 0)
while True:
    x, y = current
    visited[x][y] = True

    value = G[x][y]
    if value == "U":
        new_current = (x - 1, y)
    elif value == "D":
        new_current = (x + 1, y)
    elif value == "R":
        new_current = (x, y + 1)
    else:
        new_current = (x, y - 1)

    new_x, new_y = new_current
    if new_x < 0 or new_x >= H:
        ans = (x, y)
        break
    if new_y < 0 or new_y >= W:
        ans = (x, y)
        break

    if visited[new_x][new_y]:
        break

    current = new_current

ans_x, ans_y = ans

if ans_x == -1:
    print(-1)
else:
    print(ans_x + 1, ans_y + 1, sep=" ")
