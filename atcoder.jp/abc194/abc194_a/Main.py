a, b = map(int, input().split())

nyukokei = a + b

if (nyukokei >= 15 and b >= 8):
    print(1)
elif(nyukokei >= 10 and b >= 3):
    print(2)
elif(nyukokei >= 3):
    print(3)
else:
    print(4)

