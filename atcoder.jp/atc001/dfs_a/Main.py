import sys
sys.setrecursionlimit(10**7)

h, w = map(int, input().split())
c = [list(input()) for _ in range(h)]
seen = [[0] * w for _ in range(h)]


def dfs(x, y):
    if x >= h or x < 0 or y < 0 or y >= w or c[x][y] == '#' or seen[x][y]:
        return

    if c[x][y] == 'g':
        print("Yes")
        exit()

    seen[x][y] = 1

    dfs(x + 1, y)
    dfs(x - 1, y)
    dfs(x, y + 1)
    dfs(x, y - 1)


for i in range(h):
    for j in range(w):
        if c[i][j] == 's':
            sx, sy = i, j

dfs(sx, sy)
print("No")
