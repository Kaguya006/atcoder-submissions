import sys
input = sys.stdin.readline

v, t, s, d = map(int, input().split())

x1 = v * t
x2 = v * s

if x1 <= d and d <= x2:
    print("No")
else:
    print("Yes")
