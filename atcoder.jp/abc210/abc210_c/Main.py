n, k = map(int, input().split())
c = input().split()

d = {}
for i in range(k):
  t = c[i]
  if t in d:
    d[t] += 1
  else:
    d[t] = 1

ans = len(d)
for i in range(k, n):
  t = c[i - k]
  d[t] -= 1
  if d[t] == 0:
    del d[t]
  
  tt = c[i]
  if tt in d:
    d[tt] += 1
  else:
    d[tt] = 1

  
  ans = max(ans, len(d))

print(ans)