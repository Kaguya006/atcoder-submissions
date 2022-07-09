n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]
ans = 0

def is_online(i, j, k):
    # i - j - k
    ij_vec = (j[0] - i[0], j[1] - i[1])
    jk_vec = (k[0] - j[0], k[1] - j[1])

    if jk_vec[0] == 0:
        if ij_vec[0] == 0:
            return True
        else:
            return False

    if jk_vec[1] == 0:
        if ij_vec[1] == 0:
            return True
        else:
            return False

    k1 = ij_vec[0] / jk_vec[0]
    k2 = ij_vec[1] / jk_vec[1]

    if k1 == k2:
        return True
    
    return False

for i in range(n):
    for j in range(i + 1, n):
        for k in range(j + 1, n):
            online = is_online(a[i], a[j], a[k])
            if not online:
                ans += 1
print(ans)