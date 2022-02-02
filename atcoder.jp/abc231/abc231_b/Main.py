n = int(input())
dict = {}
for _ in range(n):
    s = input().strip()
    if s not in dict:
        dict[s] = 1
    else:
        dict[s] += 1
print(sorted(dict.items(), key=lambda item: item[1], reverse=True)[0][0])
