n = int(input())
s = input()

even = True if (s.find("1") + 1) % 2 == 0 else False

if even:
    print("Aoki")
else:
    print("Takahashi")
