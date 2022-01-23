import sys
input = sys.stdin.readline

n, x = map(int, input().split())
a = list(map(int, input().split()))

ans = []
for t in a:
    if x == t: continue
    ans.append(t)
print(*ans)
