#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[1002];
int fire[1002][1002];
int jihoon[1002][1002];
int n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++){
    fill(fire[i], fire[i]+m, -1);
    fill(jihoon[i], jihoon[i]+m, -1);
  }
  for (int i = 0; i < n; i++) cin >> board[i];

  queue<pair<int,int>> F;
  queue<pair<int,int>> J;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if(board[i][j] == 'F'){
        F.push({i,j});
        fire[i][j] = 0;
      }
      if(board[i][j] == 'J'){
        J.push({i,j});
        jihoon[i][j] = 0;
      }
    }
  }

  //불에 대한 BFS
  while(!F.empty()){
    auto cur = F.front(); F.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(fire[nx][ny] >= 0 || board[nx][ny] == '#') continue;
      fire[nx][ny] = fire[cur.X][cur.Y] + 1;
      F.push({nx,ny});
    }
  }

  while(!J.empty()){
    auto cur = J.front(); J.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m){
        cout << jihoon[cur.X][cur.Y]+1;
        return 0;
      }
      if (jihoon[nx][ny] >= 0 || board[nx][ny] == '#') continue;
      if (fire[nx][ny] != -1 && fire[nx][ny] <= jihoon[cur.X][cur.Y]+1) continue;
      jihoon[nx][ny] = jihoon[cur.X][cur.Y]+1;
      J.push({nx,ny});
    }
  }
  cout << "IMPOSSIBLE";
}