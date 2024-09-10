#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int T;
  int N;

  vector<vector<int>> cnt(41, vector<int>(2));
  cnt[0][0] = 1;
  cnt[0][1] = 0;
  cnt[1][0] = 0;
  cnt[1][1] = 1;
  for (int i = 2; i < 41; i++) {
    cnt[i][0] = cnt[i-1][0]+ cnt[i-2][0];
    cnt[i][1] = cnt[i-1][1] + cnt[i-2][1];
  }

  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> N;
    cout << cnt[N][0] << " " << cnt[N][1] << endl;
  }
}