n = int(input())

ok = True
existence = []
for i in range(n):
    s = input()
    if s[0] not in ["H", "D", "C", "S"]:
        ok = False
    if s[1] not in ["A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K"]:
        ok = False
    if s in existence:
        ok = False
    existence.append(s)

if ok:
    print("Yes")
else:
    print("No")
