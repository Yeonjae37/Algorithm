def calc(A, B, C):
  if A == B == C :
    return 10000 + int(A) * 1000
  elif A == B or B == C or A == C :
    if A == B or A == C :
      return 1000 + int(A) * 100
    else:
      return 1000 + int(C) * 100
  else: 
    return int(max(A, B, C)) * 100

def main():
  A, B, C = input().split()
  print(calc(A,B,C))

if __name__ == "__main__":
  main()