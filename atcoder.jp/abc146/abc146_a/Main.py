s = input().strip()
t = [7 - i for i in range(7)]
tt = ['SUN','MON','TUE','WED','THU','FRI','SAT']
d = {day:cost for day, cost in zip(tt, t)}
print(d[s])
