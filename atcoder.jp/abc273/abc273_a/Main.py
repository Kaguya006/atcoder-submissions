def rec(n):
    if n == 0:
        return 1
    return n * rec(n - 1)


N = int(input())
print(rec(N))
