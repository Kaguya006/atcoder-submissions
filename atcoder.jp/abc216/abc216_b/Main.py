n = int(input())

ok = False
existence = []
for i in range(n):
    s = input()
    if s in existence:
        ok = True
    existence.append(s)

if ok:
    print("Yes")
else:
    print("No")
