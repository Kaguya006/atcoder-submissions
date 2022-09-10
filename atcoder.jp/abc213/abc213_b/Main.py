n = int(input())
a_org = list(map(int, input().split()))
a = sorted(a_org)
print(a_org.index(a[-2]) + 1)
