import sys
input = sys.stdin.readline

s = list(input().strip())

for i in range(len(s)):
    if (i + 1) % 2 == 1:
        if not s[i].islower():
            print("No")
            exit()
    else:
        if s[i].islower():
            print("No")
            exit()
print("Yes")
