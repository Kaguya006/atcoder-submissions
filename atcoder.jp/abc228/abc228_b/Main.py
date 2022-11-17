n, x = map(int, input().split())
a = list(map(int, input().split()))

visited = [False] * n
current = x - 1
while not visited[current]:
    visited[current] = True
    current = a[current] - 1
print(visited.count(True))