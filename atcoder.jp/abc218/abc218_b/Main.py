p = list(map(int, input().split()))
ans = ""
for x in p:
    ans += chr(96 + x)
print(ans)
