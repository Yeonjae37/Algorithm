N = int(input())

a = 0
for i in range(N*2-1, 0, -2):
  print(" "*a + "*"*i)
  a+=1

for i in range(3, N*2+1, 2):
  print(" "*((N*2-i)//2) + "*"*i)