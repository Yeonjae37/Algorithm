#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

void calc(int N, int arr[]) {
    // DP 테이블 초기화
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = 0;
        }
    }

    // 카드가 한 장만 남은 경우, 그 카드를 뽑도록 초기화
    for (int i = 1; i <= N; i++) {
        dp[i][i] = arr[i];
    }

    // 카드가 2장 이상 남은 경우
    for (int cardsNum = 2; cardsNum <= N; cardsNum++) { //카드 몇장 남았는지
        for (int i = 1; i <= N - cardsNum + 1; i++) { //남은 카드 중 시작점
            int j = i + cardsNum - 1;  //남은 카드 중 끝점

            
            dp[i][j] = max(arr[i] + min(dp[i + 1][j - 1], dp[i + 2][j]), //근우가 왼쪽 끝 카드를 선택할 때
                           arr[j] + min(dp[i + 1][j - 1], dp[i][j - 2])); //근우가 오른쪽 끝 카드를 선택할 때

            /*
            arr[i] : 근우가 왼쪽 끝 카드를 선택했을 때 점수
            dp[i+1][j-1], dp[i+2],[j] : 근우가 선택한 후 남은 구간 중 명우가 선택
            max : 근우가 선택할 수 있는 카드 중에서 더 많은 점수
            min : 명우가 근우 점수를 최소화 할 때
            */
           
        }
    }

    cout << dp[1][N] << "\n";
}

int main(void) {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N; 
        int cards[1001];

        for (int i = 1; i <= N; i++) {
            cin >> cards[i];
        }

        calc(N, cards);
    }

    return 0;
}