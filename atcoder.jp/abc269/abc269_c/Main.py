from copy import copy

ans = set()


def dfs(s, current):
    ans.add(int("".join(s), 2))

    size = len(s)
    if current == size:
        return

    for i in range(current, size):
        if s[i] == "1":
            tmp = copy(s)
            tmp[i] = "0"
            dfs(tmp, i + 1)
            dfs(s, i + 1)
            return


N = int(input())
bin = "{0:b}".format(N)
dfs(list(bin), 0)

print(*sorted(ans), sep="\n")
