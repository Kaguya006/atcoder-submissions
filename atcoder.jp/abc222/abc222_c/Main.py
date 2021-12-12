n, m = map(int, input().split())
a = [(list(input()), i) for i in range(2 * n)]
dic = {}
for i in range(2 * n): dic[i] = 0  

def versus(p1, p2, rnd):
    h_a, h_b = p1[rnd], p2[rnd]
    if h_a == 'G':
        if h_b == 'C':
            return True
        elif h_b == 'P':
            return False
    elif h_a == 'C':
        if h_b == 'G':
            return False
        elif h_b == 'P':
            return True
    elif h_a == 'P':
        if h_b == 'G':
            return True
        elif h_b == 'C':
            return False

for i in range(m):
    sorted_dic = sorted(dic.items(), key = lambda x: (-x[1], x[0]))
    previous_idx, j = -1, 1
    for current in sorted_dic:
        current_idx = current[0]
        if not j % 2 == 0:
            j += 1
            previous_idx = current_idx
        else:
            j += 1
            if a[previous_idx][0][i] == a[current_idx][0][i]: continue
            if versus(a[previous_idx][0], a[current_idx][0], i):
                dic[previous_idx] += 1
            else:
                dic[current_idx] += 1

ans = sorted(dic.items(), key = lambda x: (-x[1], x[0]))
for e in ans:
    print(e[0] + 1)

