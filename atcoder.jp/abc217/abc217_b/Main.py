all = {"ABC", "ARC", "AGC", "AHC"}
a = {input() for _ in range(3)}

print((all - a).pop())
