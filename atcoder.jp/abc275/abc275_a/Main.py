N = int(input())
H = list(map(int, input().split()))
biggest = -1
ans = -1

for i, a in enumerate(H):
    if biggest < a:
        biggest = a
        ans = i + 1
print(ans)
