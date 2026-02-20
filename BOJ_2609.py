a, b = input().split()
a = int(a)
b = int(b)

def gcd(a, b):
  if b == 0:
    return a
  return gcd(b, a%b)

def lcm(a, b):
  return (a*b)  // gcd(a,b)

print(gcd(a, b))
print(lcm(a, b))