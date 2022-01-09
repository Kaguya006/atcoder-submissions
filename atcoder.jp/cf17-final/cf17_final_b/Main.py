from collections import Counter
s = list(input())
most_common = Counter(s).most_common()
ok = False

if len(most_common) == 1:
    if most_common[0][1] == 1:
        ok = True
elif len(most_common) == 2:
    if most_common[0][1] == 1 and most_common[1][1] == 1:
        ok = True
else:
    a, b, c = [most_common[0][1], most_common[1][1], most_common[2][1]]

    if a - c <= 1 and b - c <= 1:
        ok = True
if ok:
    print("YES")
else:
    print("NO")
