k = int(input())
a, b = input().split()

t_a = 0
t_b = 0

for i in range(len(a)):
    t_a += pow(k, i) * int(a[len(a) - i - 1])

for i in range(len(b)):
    t_b += pow(k, i) * int(b[len(b) - i - 1])

print(t_a * t_b)
