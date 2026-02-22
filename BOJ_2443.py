N = int(input())
blank = " "
dot = "*"
for i in range(N*2-1, 0, -2):
  print(blank*(N - (i+1)//2) + dot*i)