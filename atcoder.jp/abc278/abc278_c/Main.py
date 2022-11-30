N, Q = map(int, input().split())

relations = set()
ans = []
for i in range(Q):
    t, a, b = map(int, input().split())

    if t == 1:
        relations.add((a, b))
    elif t == 2:
        relations.discard((a, b))
    else:
        if (a, b) in relations and (b, a) in relations:
            ans.append("Yes")
        else:
            ans.append("No")

print(*ans, sep="\n")