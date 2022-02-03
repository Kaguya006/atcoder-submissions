MAX = 1000000
n = int(input())

a = []
for i in range(1, MAX + 1):
    a.append(int(str(i) + str(i)))
a.sort()

left = 0
right = MAX
while left <= right:
    mid = (left + right) // 2

    if a[mid] == n:
        print(mid + 1)
        exit()
    elif a[mid] < n:
        left = mid + 1
    else:
        right = mid - 1
print(right + 1)
