N = int(input())
total = 0

for i in range(N):
  A, B = map(int, input().split())
  total += B%A

print(total)