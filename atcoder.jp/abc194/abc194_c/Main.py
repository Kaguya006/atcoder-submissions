import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))


s = [0]
for i in range(n):
    s.append(s[i] + a[i])

s2 = [0]
for i in range(n):
    s2.append(s2[i] + (a[i] * a[i]))

ans = 0
for i in range(n - 1):
    b = a[i]
    ans += (s2[n] - s2[i + 1]) + (-2*b*(s[n] - s[i + 1])) + ((n - i - 1)*(b * b))
print(ans)
