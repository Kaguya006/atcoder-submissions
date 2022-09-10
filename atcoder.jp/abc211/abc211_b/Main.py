from sys import exit

targets = {t: False for t in ["H", "2B", "3B", "HR"]}
for i in range(4):
    s = input()
    targets[s] = True

for k, v in targets.items():
    if not v:
        print("No")
        exit(0)

print("Yes")
