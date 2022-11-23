x, y, z = map(int, input().split())

ans = -1
if x > 0:
    if y > 0:
        if x < y:
            ans = x
        else:
            if z > 0:
                if z < y or x < y:
                    ans = x
            else:
                ans = -2 * z + x
    else:
        ans = x
else:
    if y > 0:
        ans = -1 * x
    else:
        if x > y:
            ans = -1 * x
        else:
            if z > 0:
                ans = 2 * z + -1 * x
            else:
                if z > y or x > y:
                    ans = -1 * x

print(ans)
