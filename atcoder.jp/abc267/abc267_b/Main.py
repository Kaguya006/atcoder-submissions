s = input()
c1 = [s[6]]
c2 = [s[3]]
c3 = [s[7], s[1]]
c4 = [s[0], s[4]]
c5 = [s[2], s[8]]
c6 = [s[5]]
c7 = [s[9]]
pins = [c1, c2, c3, c4, c5, c6, c7]

is_split = False
for i in range(7):
    flug = False
    for j in range(i + 1, 7):
        if "1" not in pins[j]:
            flug = True
            continue

        if flug:
            if s[0] == "0" and "1" in pins[i] and "1" in pins[j]:
                is_split = True

if is_split:
    print("Yes")
else:
    print("No")