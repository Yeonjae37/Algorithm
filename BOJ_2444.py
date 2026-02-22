N = int(input())
blank = " "
dot = "*"
for i in range(1, N*2, 2):
  print(blank*((N*2-i)//2) + dot*i)
for i in range(N*2-3, 0, -2):
  print(blank*(N - (i+1)//2) + dot*i)