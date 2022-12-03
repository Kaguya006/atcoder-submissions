N, M, T = map(int, input().split())
A = list(map(int, input().split()))
for i in range(M):
    x, y = map(int, input().split())
    x -= 1
    A[x] -= y

ok = False
i = 0
while T > 0 and i < len(A):
    T -= A[i]
    i += 1

    if T > 0 and i == len(A):
        ok = True

if ok:
    print("Yes")
else:
    print("No")
