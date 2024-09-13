#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int T;
  cin >> T;
  vector<unsigned long long> num(T, 0);
  for (int i = 0; i < T; i++) {
    int N, M;
    cin >> N >> M;
    int ans = 1;
    for (int j = 0; j < N; j++)  {
      ans *= (M - j);
      ans /= j+1;
      num[i] = ans;
    }
  }

  for (int j = 0; j < T; j++) {
    cout << num[j] << endl;
  }

}