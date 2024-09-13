#include <bits/stdc++.h>
using namespace std;
vector<int> num(1000001, 0);

int main(void) {
  int N;
  cin >> N;
  num[1] = 1;
  num[2] = 2;

  for (int i = 3; i <= N; i++) {
    num[i] = (num[i-1] + num[i-2])%15746;
  }

  cout << num[N];

}