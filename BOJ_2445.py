N = int(input())
dot = "*"
blank = " "

for i in range(1, N+1):
  print(dot*i + blank*(N-i)*2 + dot*i)

for i in range(N-1, 0, -1):
  print(dot*i + blank*(N-i)*2 + dot*i)