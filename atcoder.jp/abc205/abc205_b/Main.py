n = int(input())
a = list(map(int, input().split()))
t = [i for i in range(1, n + 1)]

if sorted(a) == t:
    print("Yes")
else:
    print("No")
