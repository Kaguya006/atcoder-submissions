s = input()

a = []
for i in range(len(s)):
    t = ""
    for j in range(len(s)):
        t += s[(i + j) % len(s)]
    a.append(t)

sorted_a = sorted(a)
print(sorted_a[0])
print(sorted_a[-1])
