s, t, x = map(int, input().split())

yes = False
if s < t:
    if s <= x < t:
        yes = True
else:
    if not t <= x < s:
        yes = True

if yes:
    print("Yes")
else:
    print("No")
