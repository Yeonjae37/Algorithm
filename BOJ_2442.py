N = int(input())
blank = " "
dot = "*"
for i in range(1, N*2, 2):
  print(blank*((N*2-i)//2) + dot*i)