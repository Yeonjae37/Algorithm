import math

M = int(input())
N = int(input())

sum = 0
min = 100001

for i in range(M, N+1):
  r = math.isqrt(i)
  if r*r == i:
    sum += i
    if i < min: min = i

if sum == 0: print(-1)
else: print(sum, min)
