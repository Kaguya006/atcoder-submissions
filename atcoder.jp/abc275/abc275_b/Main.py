mod = 998244353
a, b, c, d, e, f = map(int, input().split())
print((a * b % mod * c - d * e % mod * f) % mod)