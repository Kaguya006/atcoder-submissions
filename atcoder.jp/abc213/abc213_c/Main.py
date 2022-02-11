import sys
import bisect
input = sys.stdin.readline

h, w, n = map(int, input().split())

a = [0] * n
b = [0] * n
row = set()
col = set()
for i in range(n):
    a[i], b[i] = map(int, input().split())
    row.add(a[i])
    col.add(b[i])

row = list(row)
col = list(col)
row.sort()
col.sort()

for i in range(n):
    row_idx = bisect.bisect_left(row, a[i])
    col_idx = bisect.bisect_left(col, b[i])

    print(row_idx + 1, col_idx + 1)
