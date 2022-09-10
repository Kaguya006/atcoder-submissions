import sys

n, x = map(int, input().split())
a = map(int, input().split())

even = False
for t in a:
    if even:
        x -= (t - 1)
        even = False
    else:
        x -= t
        even = True

    if x < 0:
        print("No")
        sys.exit(0)

print("Yes")
