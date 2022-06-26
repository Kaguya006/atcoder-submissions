s = input()
t = "oxxoxxoxxoxx"

for i in range(12):
    for j in range(i, 12 + 1):
        if s == t[i:j]:
            print("Yes")
            exit()

print("No")