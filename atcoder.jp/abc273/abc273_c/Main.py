import typing as t
from collections import defaultdict

N = int(input())
A = list(map(int, input().split()))
cnt: t.Dict[int, int] = defaultdict(int)


def bsearch(a_nondup: t.List[int], tgt):
    size = len(a_nondup)
    left = 0
    right = size - 1

    while left < right:
        mid = (left + right) // 2
        if tgt > a_nondup[mid]:
            left = mid + 1
        else:
            right = mid
    return size - 1 - right


a_nondup = list(set(A))
a_nondup.sort()
for i in range(N):
    x = bsearch(a_nondup, A[i])
    cnt[x] += 1

for i in range(N):
    print(cnt[i])