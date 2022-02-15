n = int(input())
p = [int(input()) for _ in range(n)]
print(int(max(p) / 2 + sum(p) - max(p)))