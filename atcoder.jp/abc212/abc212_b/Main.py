s = input()
weak = True
for i in range(1, len(s)):
    if (int(s[i - 1]) + 1) % 10 != int(s[i]):
        weak = False
if s == s[0] * 4 or weak:
    print("Weak")
else:
    print("Strong")
