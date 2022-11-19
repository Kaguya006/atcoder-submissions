h, w = map(int, input().split())
c = []
for i in range(h):
    s = input()
    c.append(list(s))

ans = list()
for i in range(w):
    cnt = 0
    for j in range(h):
        if c[j][i] == "#":
            cnt += 1
    ans.append(cnt)

print(*ans)