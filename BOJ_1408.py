b_h, b_m, b_s = map(int, input().split(':'))
a_h, a_m, a_s = map(int, input().split(':'))

before = (b_h*60*60) + (b_m*60) + b_s
after = (a_h*60*60) + (a_m*60) + a_s

if before > after:
  time = before - after
  time = abs(time)
  time = 86400 - time
else:
  time = after - before
  time = abs(time)
  go = False
hour = 0
min = 0
sec = 0

if time!=0:
  hour = time//3600
  time = time%3600
  if time!=0:
    min = time//60
    time = time%60
    if time!=0: sec = time

ans = ""

if hour < 10:
  ans = ans + "0"
  ans = ans + str(hour)
else:
  ans = ans + str(hour)
ans = ans + ":"
if min < 10:
  ans = ans + "0"
  ans = ans + str(min)
else:
  ans = ans + str(min)
ans = ans + ":"
if sec < 10:
  ans = ans + "0"
  ans = ans + str(sec)
else:
  ans = ans + str(sec)

print(ans)