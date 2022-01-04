from itertools import product

# A = [1, 4, 13, 34]
# n = len(A)
# 
# for bits in product([0, 1], repeat = n):
#     print("bits: ", bits)
#     a = [x for bit, x in zip(bits, A) if bit == 1]
#     if not a: continue
# 
#     print("chosen:", a)
#     print("sum: ", sum(a))
#     if sum(a) % 3 == 0:
#         print("Yes")
#         exit()

n = list(input())
ans = 0

def calc(a, b):
    t1 = "".join(sorted(a, reverse = True))
    t2 = "".join(sorted(b, reverse = True))

    return int(t1) * int(t2)

for bits in product([0, 1], repeat = len(n)):
    left = []
    right = []
    for i in range(len(n)):
        if bits[i]:
            left.append(n[i])
        else:
            right.append(n[i])

    if not left or not right:
        continue

    ans = max(ans, calc(left, right))

print(ans)
