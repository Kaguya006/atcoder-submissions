N = int(input())
t = [str(i) for i in range(10)]
t += ["A", "B", "C", "D", "E", "F"]

a = N // 16
b = N % 16

print(f"{t[a]}{t[b]}")
