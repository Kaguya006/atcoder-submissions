m = int(input())

if m < 100:
    print("00")
elif m <= 5000:
    t = m * 10 // 1000
    if t < 10:
        print(f"0{t}")
    else:
        print(f"{t}")
elif m <= 30000:
    t = m // 1000 + 50
    print(f"{t}")
elif m <= 70000:
    t = int((m // 1000 - 30) // 5) + 80
    print(f"{t}")
else:
    print("89")
