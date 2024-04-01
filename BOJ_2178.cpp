#include <bits/stdc++.h>
using namespace std;

int main(void){
  queue<pair<int,int>> Q;
  int res = 0;
  int N; //세로
  int M; //가로
  cin >> N;
  cin >> M;
  vector<vector<int>> maze(N, vector<int>(M,0));
  vector<vector<int>> visit(N, vector<int> (M, -1)); // 총 몇칸을 지나왔는지 저장
  // 모든 칸은 -1로 초기화 시켜놓음
  for (int i = 0; i < N; i++) {
    string row; // 현재 줄을 저장할 문자열
    cin >> row; // 문자열로 한 줄을 입력 받음
    for (int j = 0; j < M; j++) {
      maze[i][j] = row[j] - '0'; // 각 문자를 정수로 변환하여 저장
    }
  }
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0 ,-1};

  Q.push({0,0}); //시작 지점 큐에 삽입
  int nx;
  int ny;

  while(!Q.empty()){
    pair <int, int> cur = Q.front(); Q.pop();
    for (int i = 0; i < 4; i++){
      nx = cur.first + dx[i];
      ny = cur.second + dy[i];

      if (nx >= N || nx < 0 || ny >= M || ny < 0) continue;
      if (maze[nx][ny] == 0 || visit[nx][ny] >= 0) continue;
      // -1인 경우 방문 X. -1보다 큰 경우 방문 완료. 최소 칸으로 업데이트
      visit[nx][ny] = visit[cur.first][cur.second] + 1;
      Q.push({nx, ny});
    }
  }
  cout << visit[N - 1][M - 1] + 2 << endl;
}