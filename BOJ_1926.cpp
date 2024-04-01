#include <bits/stdc++.h>
using namespace std;

queue<pair<int, int>> Q;

int main(void){
  int n; //세로
  int m; //가로
  int temp;
  int time = 0;
  int res = 0;
  cin >> n;
  cin >> m;
  vector<vector<int>> paper(n, vector<int>(m,0)); //도화지
  vector<vector<int>> visit(n, vector<int>(m,0)); //방문 여부를 표시하는 2차원 벡터
  for (int i = 0; i < n; i++){ //도화지 입력
    for (int j = 0; j < m; j++){
      cin >> paper[i][j];
    }
  }

  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if ((visit[i][j] == 0) && (paper[i][j] == 1)){
        time++;
        Q.push({i, j});
        visit[i][j] = 1;
        int size = 1;
        int dx[4] = {1, 0, -1, 0}; //상 하 좌 우
        int dy[4] = {0, 1, 0, -1};
        while (!Q.empty()){
          pair <int, int> cur = Q.front(); Q.pop();
          for (int k = 0; k < 4; k++){
            int nx = cur.first + dx[k];
            int ny = cur.second + dy[k];
            if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
            if (paper[nx][ny] == 0 || visit[nx][ny] == 1) continue;
            visit[nx][ny] = 1;
            if (paper[nx][ny] == 1) {
              Q.push({nx, ny});
              size++;
            }
          }
        }
      res = max (res, size);
      }
    }
  }
  cout << time << endl;
  cout << res;
}