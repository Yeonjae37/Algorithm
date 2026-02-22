n = int(input())

0, 1, 1, 2, 3, 5

def fib(a, b, c):
  if a == n:
    print(b)
    return 0
  fib(a+1, c, b+c)


fib(0, 0, 1)