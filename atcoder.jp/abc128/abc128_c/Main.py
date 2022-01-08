n, m = map(int, input().split())
ks = [list(map(int, input().split())) for _ in range(m)]
p = [int(i) for i in input().split()]
ans = 0

for bit in range(1 << n):
  ok = True
  for i in range(m):
    cnt = 0
    for j in range(ks[i][0]):
      cnt += bit >> (ks[i][j + 1] - 1) & 1
    if cnt % 2 != p[i]: ok = False
  if ok: ans += 1

print(ans)