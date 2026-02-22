N = int(input())
blank = " "
dot = "*"
for i in range(1, N*2, 2):
  print(dot*(i//2+1))
for i in range(N*2-3, 0, -2):
  print(dot*(i//2+1))