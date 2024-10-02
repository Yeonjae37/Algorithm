#include <bits/stdc++.h>
using namespace std;
/*
토로이드 그래프 -> 마지막 열, 첫번째 열 연결!! / 마지막 행, 첫번째 행 연결!!!
짝수 행 : 왼쪽 -> 오른쪽
홀수 행 : 오른쪽 -> 왼쪽
*/

void cycle(int m, int n) {
    cout << 1 << "\n";  // m x n에서 사이클은 무조건 존재

    // 첫번째 행 : 왼쪽 -> 오른쪽
    for (int j = 0; j < n; j++) {
        cout << "(" << 0 << ", " << j << ")\n";
    }

    // 첫번째 행 이후
    for (int i = 1; i < m; i++) {
        if (i % 2 == 1) { //홀수 : 오른쪽 -> 왼쪽
            for (int j = n - 1; j >= 1; j--) {
                cout << "(" << i << ", " << j << ")\n";
            }
        } else { // 짝수 : 오른쪽 -> 왼쪽
            for (int j = 1; j < n; j++) {
                cout << "(" << i << ", " << j << ")\n";
            }
        }
    }

    // 첫번째 열 방문(거꾸로) -> 짝수든 홀수든 노상관
    for (int i = m - 1; i > 0; i--) {
        cout << "(" << i << ", 0)\n";
    }
}

int main() {
  int T; cin >> T;

  for (int i = 0; i <= T; i++) {
    int m, n;
    cin >> m >> n;
    cycle(m, n);
  }
}