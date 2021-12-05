n, k = map(int, input().split())
S = [int(input()) for _ in range(n)]

ans, cur, right = 0, 1, 0

if min(S) == 0:
    ans = n
else:
    for left in range(n):
        while (right < n and cur * S[right] <= k): 
            cur *= S[right]
            right += 1
        ans = max(ans, right - left)

        if right == left:
            right += 1
        else:
            cur /= S[left]

print(ans)

