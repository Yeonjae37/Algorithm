#include <bits/stdc++.h>
using namespace std;

int wall = 3;
#define X first
#define Y second
int max_res = 0;

int virus(vector<vector<int>>& temp, int N, int M, queue<pair<int,int> > Q){ //3개의 벽을 찾으면 바이러스가 퍼지는 상황을 구현
  int dx[4] = {1, 0, -1, 0}; //상 하 좌 우
  int dy[4] = {0, 1, 0, -1};
  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      if (temp[i][j] == 2) Q.push({i, j});
    }
  }
  while(!Q.empty()){
    pair<int, int> cur = Q.front(); Q.pop();
    for (int dir = 0; dir < 4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx >= N || nx < 0 || ny >= M || ny < 0) continue;
      if (temp[nx][ny] == 1) continue;
      if (temp[nx][ny] == 0){
        temp[nx][ny] = 2;
        Q.push({nx, ny});
      }
    }
  }

  int safe = 0;
  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      if (temp[i][j] == 0) safe++;
    }
  }

  return safe;
}

int comb(vector<vector<int>>& map, int M, int N){ //3개의 벽 조합을 모두 찾는 코드
  if(wall == 0){ //3개의 벽이 모두 세워지면
    queue<pair<int,int> > Q;
    vector<vector<int>> temp(N, vector<int>(M,0));
    for (int i = 0; i < N; i++){
      for (int j = 0; j < M; j++){
        temp[i][j] = map[i][j];
      }
    }
    max_res = max(max_res, virus(temp, N, M, Q));
  }
  else {
    for (int i = 0; i < N; i++){
      for (int j = 0; j < M; j++){
        if(map[i][j] == 0){ //빈 곳이면 (벽을 세울 수 있으면)
          map[i][j] = 1;
          wall--;
          comb(map, M, N);
          map[i][j] = 0;
          wall++;
        }
      }
    }
  }
  return max_res;
}

int main(void){
  int M; // 가로
  int N; // 세로
  cin >> N >> M;
  vector<vector<int>> map(N, vector<int>(M,0));

  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      cin >> map[i][j];
    }
  }
  cout << comb(map, M, N);
}