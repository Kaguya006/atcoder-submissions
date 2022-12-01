S = input()
ans = -1

for i, a in enumerate(S):
    if a == "a":
        ans = max(ans, i + 1)
print(ans)
