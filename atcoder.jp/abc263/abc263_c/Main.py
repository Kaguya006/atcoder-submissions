from itertools import permutations

N, M = map(int, input().split())

ans = []
for p in permutations(list(range(1, M + 1)), N):
    if list(p) == sorted(p):
        ans.append(p)


for x in sorted(ans):
    for x_child in x:
        print(x_child, end=" ")
    print("")