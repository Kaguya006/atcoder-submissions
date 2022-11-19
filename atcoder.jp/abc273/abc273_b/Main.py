x, k = map(int, input().split())

for i in range(1, k + 1):
    if x % (10**i) >= 5 * (10 ** (i - 1)):
        x -= x % (10**i)
        x += 10**i
    else:
        x -= x % (10**i)
print(x)
