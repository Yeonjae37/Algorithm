#include <bits/stdc++.h>
using namespace std;

#define X 1000000000;

int main(void) {
  int N; 
  cin >> N; 

  vector<vector<int>> DP(N + 1, vector<int>(10, 1));
  //2차원 배열 만들어줌. 행 -> N(몇번째 자리인지), 열 -> 끝자리에 무슨 숫자 들어가는지

  // 길이가 1이면 0을 제외하고 1~9까지 일단 모두 1개
  // 0은 그대로 0임
  for (int i = 1; i <= 9; i++) {
    DP[1][i] = 1;
  }

  //길이가 2 이상인 계단부터 계산 시작
  for (int i = 2; i <= N; i++) {
    for (int j = 0; j <= 9; j++) {
      if (j == 0) { //마지막 자리의 숫자가 0이면 앞에 올 수 있는 자리는 1밖에 없으므로
        DP[i][j] = DP[i-1][1] % X;
      }
      else if (j == 9) { //마지막 자리의 숫자가 9이면 앞에 올 수 있는 자리는 8밖에 없으므로
        DP[i][j] = DP[i-1][8] % X;
      }
      else { //나머지 숫자의 경우 올 수 있는 숫자는 j-1, j+1이 있으므로
        DP[i][j] = (DP[i-1][j-1] + DP[i-1][j+1]) % X;
      }
    }
  }

  long long ans = 0;
  for (int i = 0; i <= 9; i++) {
    ans += DP[N][i];
  }

  cout << ans % X;

  return 0;
}