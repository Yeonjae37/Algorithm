#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){ //최대 공약수 구함
  return a % b ? gcd(b, a%b) : b;
}

int main(void){
  int T, GCD;
  cin >> T;
  for (int i = 0; i < T; i++){
    int a, b;
    cin >> a >> b;

    while(a != 1){
      int f = b/a + 1;
      a = a*f - b;
      b = f*b;
      GCD = gcd(a,b);
      a /= GCD; //a를 최대 공약수로 나눔
      b /= GCD; //b를 최대 공약수로 나눔
    }
    cout << b << "\n";
  }
}