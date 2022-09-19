h, w = map(int, input().split())
a = []
for _ in range(h):
    a.append(list(map(int, input().split())))

ok = True

for i_1 in range(h):
    for i_2 in range(h):
        for j_1 in range(w):
            for j_2 in range(w):
                if i_1 <= i_2 and j_1 <= j_2:
                    if not a[i_1][j_1] + a[i_2][j_2] <= a[i_2][j_1] + a[i_1][j_2]:
                        ok = False

if ok:
    print("Yes")
else:
    print("No")
