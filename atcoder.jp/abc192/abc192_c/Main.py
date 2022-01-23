import sys
input = sys.stdin.readline

n, k = map(int, input().split())

current = str(n)
for i in range(k):
    t1, t2 = [''.join(sorted(current)), ''.join(sorted(current, reverse = True))]
    current = str(int(t2) - int(t1))
print(current)
