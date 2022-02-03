n, q = map(int, input().split())
a = sorted(list(map(int, input().split())))

data = [int(input()) for _ in range(q)]
ans = []

for target in data:
    left = 0
    right = n - 1
    while left <= right:
        mid = (left + right) // 2

        if a[mid] == target:
            ans.append(n - mid)
            break
        elif a[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

        if right < left:
            ans.append(n - (right + 1))

for t in ans:
    print(t)
