import sys
input = sys.stdin.readline

m, h = map(int, input().split())

if h % m != 0:
    print('No')
else:
    print('Yes')
