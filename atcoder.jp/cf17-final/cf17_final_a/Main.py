import sys
input = sys.stdin.readline

a = list('AKIHABARA')
s = input().strip()

for i in range(1 << 9):
    t = ''
    for j in range(9):
        if ((1 << j) & i) and a[j] == 'A':
            continue
        else:
            t += a[j]
    if t == s:
        print("YES")
        exit()
print("NO")
