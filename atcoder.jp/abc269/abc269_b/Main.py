S = [input() for _ in range(10)]
A = 10 * 7
B = -1
C = 10 * 7
D = -1

for i in range(10):
    for j in range(10):
        if S[i][j] == "#":
            A = min(A, i + 1)
            B = max(B, i + 1)
            C = min(C, j + 1)
            D = max(D, j + 1)

print(A, B, sep=" ")
print(C, D, sep=" ")
