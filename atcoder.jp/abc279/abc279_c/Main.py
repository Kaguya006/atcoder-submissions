H, W = map(int, input().split())
S = [input() for _ in range(H)]
T = [input() for _ in range(H)]

trp_s = []
trp_t = []
for j in range(W):
    tmp_s = []
    tmp_t = []
    for i in range(H):
        tmp_s.append(S[i][j])
        tmp_t.append(T[i][j])
    trp_s.append(tmp_s)
    trp_t.append(tmp_t)

if sorted(trp_s) == sorted(trp_t):
    print("Yes")
else:
    print("No")