import math
s = input()
t = set(s)
print(int(math.factorial(len(s)) / math.factorial(len(s) - len(t) + 1)))
