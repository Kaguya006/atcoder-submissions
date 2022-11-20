N, M = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(M)]
friends = [[False for _ in range(N)] for _ in range(N)]
for i in range(M):
    for j in range(len(a[i][1:])):
        person_1 = a[i][j + 1]
        for k in range(j + 1, len(a[i][1:])):
            person_2 = a[i][k + 1]
            friends[person_1 - 1][person_2 - 1] = True
            friends[person_2 - 1][person_1 - 1] = True
for i in range(N):
    if friends[i].count(False) != 1:
        print("No")
        exit()
print("Yes")