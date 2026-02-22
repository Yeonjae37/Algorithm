T = int(input())

for i in range(T):
  N = int(input())
  total = 0
  gpa = 0.0
  for j in range(N):
    C, G = input().split()
    C = int(C)
    G = float(G)
    total += C
    gpa += G * C
  print(total, round(gpa/total, 1))