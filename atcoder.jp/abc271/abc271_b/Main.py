N, Q = map(int, input().split())
A = list()
ans = list()
for i in range(N):
    a = list(map(int, input().split()))
    A.append(a[1:])

for i in range(Q):
    s, t = map(int, input().split())
    s -= 1
    t -= 1
    ans.append((A[s][t]))

for x in ans:
    print(x)