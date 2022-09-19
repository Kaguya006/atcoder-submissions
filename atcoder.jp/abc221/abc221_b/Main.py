s = input()
t = input()

ok = False

if s != t:
    for i in range(1, len(s)):
        u = list(s)
        u[i], u[i-1] = u[i-1], u[i]
        if "".join(u) == t:
            ok = True
else:
    ok = True

if ok:
    print("Yes")
else:
    print("No")
