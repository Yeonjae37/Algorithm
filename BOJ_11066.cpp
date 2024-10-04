#include<bits/stdc++.h>
using namespace std;

int cost[501];
int dp[501][501];

int main(void){
  int T; cin >> T;
  while (T--){
    int K; cin >> K; //소설 장 수
    for (int i = 1; i <= K; i++){
      cin >> cost[i];
    }

    for (int i = 1; i <= K; i++){ //본인을 합칠때는 0으로
      dp[i][i] = 0;
    }

    for (int l = 2; l <= K; l++) { // 구간 길이
      for (int i = 1; i<= K - l + 1; i++) {
        int j = i + l - 1; //끝나는 구간
        dp[i][j] = INT_MAX;

        int total = 0;
        for (int c = i; c <= j; c++) {
          total += cost[c];
        }

        for (int k = i; k < j; k++) { //중간 지점 k
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + total);
        }
        /*
        {40, 30, 30, 50}일 때,
        구간 길이가 3이고, [1,3]을 볼 때, (40, 30, 30)
        k = 1이면, dp[1][1] + dp[2][3] + 100 = 160 -> min(INT_MAX, 160)
        k = 2이면, dp[1][2] + dp[3][3] + 100 = 170 -> min(160, 170)
        결론은 160!
        */
      }
    }
    cout << dp[1][K] << "\n";
  }
  return 0;
}