X, Y, N = map(int, input().split())

if X < Y / 3:
    print(X * N)
else:
    print(N // 3 * Y + X * (N % 3))
