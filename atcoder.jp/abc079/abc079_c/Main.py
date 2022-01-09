a = list(map(int, list(input())))

for bits in range(1 << 3):
    sum = 0
    s = ""
    for i in range(4):
        if i == 0:
            sum += a[i]
            s += str(a[i])
            continue

        if bits >> (i - 1) & 1:
            sum += a[i]
            s += '+'
        else:
            sum -= a[i]
            s += '-'
        s += str(a[i])

    if sum == 7:
        print(s + "=7")
        exit()
