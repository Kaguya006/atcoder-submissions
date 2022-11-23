h, m = map(int, input().split())
for minute in range(h * 60 + m, h * 60 + m + 24 * 60):
    a = minute // 60 % 24 // 10
    b = minute // 60 % 24 % 10
    c = minute % 60 // 10
    d = minute % 60 % 10

    if int(str(a) + str(c)) <= 23 and int(str(b) + str(d)) <= 59:
        print(f"{str(a)+str(b)} {str(c)+str(d)}")
        exit()