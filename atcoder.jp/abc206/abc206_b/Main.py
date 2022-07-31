n = int(input())

for i in range(1, int(1e7)):
    if (((1 + i)*i)/2) >= n:
        print(i)
        exit()
