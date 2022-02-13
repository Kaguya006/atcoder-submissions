A = [list(map(int, input().split())) for _ in range(3)]
N = int(input())
b = [int(input()) for _ in range(N)]

ok = False
for i in range(3):
    if set([A[i][0], A[i][1], A[i][2]]) <= set(b):
        ok = True

for j in range(3):
    if set([A[0][j], A[1][j], A[2][j]]) <= set(b):
        ok = True

if set([A[0][0], A[1][1], A[2][2]]) <= set(b):
        ok = True

if set([A[0][2], A[1][1], A[2][0]]) <= set(b):
        ok = True

if ok:
    print("Yes")
else:
    print("No")
