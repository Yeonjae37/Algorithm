n = int(input())
players = []
for i in range(n):
  p = int(input())
  max = 0
  for j in range(p):
    C, name = input().split()
    C = int(C)
    if C > max: 
      max = C
      player = name
  players.append(player)

for i in range(len(players)):
  print(players[i])