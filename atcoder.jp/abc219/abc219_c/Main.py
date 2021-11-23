import string
alp = list(string.ascii_lowercase)
x = input()
n = int(input())

a = []
for i in range(n):
    s = input()
    a.append(s)

dic = {}
for i in range(26):
    dic[x[i]] = alp[i]

ans = {}
for i in range(len(a)):
    t = ""
    for ch in a[i]: t += str(dic[ch])
    ans[t] = a[i]

for s in sorted(ans.items(), key = lambda x:x[0]): print(s[1])
