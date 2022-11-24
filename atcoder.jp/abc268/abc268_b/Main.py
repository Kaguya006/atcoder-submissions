S = input()
T = input()

ok = False
for i in range(len(T)):
    if T[: i + 1] == S:
        ok = True
if ok:
    print("Yes")
else:
    print("No")
