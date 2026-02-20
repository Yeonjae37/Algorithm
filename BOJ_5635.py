n = int(input())
year_min = 1989
year_max = 2011
month_min = 0
month_max = 13
day_min = 0
day_max = 32
for i in range(n):
  name, d, m, y = input().split()
  y = int(y)
  m = int(m)
  d = int(d)
  if y > year_min:
    year_min = y
    month_min = m
    day_min = d
    min_name = name
  elif y == year_min:
    if m > month_min:
      year_min = y
      month_min = m
      day_min = d
      min_name = name
    elif m == month_min:
      if d > day_min:
        year_min = y
        month_min = m
        day_min = d
        min_name = name
  if y < year_max: 
    year_max = y
    month_max = m
    day_max = d
    max_name = name
  elif y == year_max:
    if m < month_max:
      year_max = y
      month_max = m
      day_max = d
      max_name = name
    elif m == month_max:
      if d < day_max:
        year_max = y
        month_max = m
        day_max = d
        max_name = name

print(min_name)
print(max_name)