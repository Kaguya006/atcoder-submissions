N, X = map(int, input().split())
P = list(map(int, input().split()))

for i, a in enumerate(P):
    if a == X:
        print(i + 1)
        exit()
