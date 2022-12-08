from pprint import pprint

R, C = map(int, input().split())

G = [[0] * 15 for _ in range(15)]

black = True
for i in range(15):
    for j in range(i, 15 - i):
        if black:
            G[i][j] = 1
            G[j][i] = 1
            G[15 - 1 - i][15 - 1 - j] = 1
            G[15 - 1 - j][15 - 1 - i] = 1
    if black:
        black = False
    else:
        black = True


if G[R - 1][C - 1] == 1:
    print("black")
else:
    print("white")
