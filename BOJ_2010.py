import sys

N = int(input())
total = 0
for i in range(N):
  a = int(sys.stdin.readline())
  if a != 1:
    total += a
  else:
    N -= 1
if N == 0:
  print(1)
else: print(total - N + 1)