#include <bits/stdc++.h>
using namespace std;

int main(void){
  int R, C; //R은 행(세로), C는 열(가로)
  cin >> R;
  cin >> C;
  bool escape = false;
  queue<pair<int,int>> fire; //불의 초기 위치를 저장해놓을 큐
  queue<pair<int,int>> J;

  vector<vector<char>> maze(R, vector<char>(C, 0)); //원본
  vector<vector<int>> visit(R, vector<int>(C, 0)); //숫자로 저장
  vector<vector<int>> Jvisit(R, vector<int>(C, 0)); //숫자로 저장

  for (int i = 0; i < R; i++){
    for (int j = 0; j < C; j++){
      cin >> maze[i][j];
      if (maze[i][j] == '#') {
        visit[i][j] = -2;
        Jvisit[i][j] = -2;
      }
      if (maze[i][j] == 'F') {
        fire.push({i, j}); //F이면, 불의 초기 위치 저장
        visit[i][j] = 0;
        Jvisit[i][j] = -1;
      }
      if (maze[i][j] == '.') {
        visit[i][j] = -1;
        Jvisit[i][j] = -1;
      }
      if (maze[i][j] == 'J') {
        J.push({i, j});
        visit[i][j] = -1;
        Jvisit[i][j] = 0;
      }
    }
  }

  /*for (int i = 0; i < R; i++){
    for (int j = 0; j < C; j++){
      cout << visit[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  for (int i = 0; i < R; i++){
    for (int j = 0; j < C; j++){
      cout << Jvisit[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;*/

  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1 , 0, -1};

  while (!fire.empty()){
    pair<int, int> cur = fire.front(); fire.pop();
    
    for (int i = 0; i < 4; i++){
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];

      if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
      if (visit[nx][ny] == -2) continue;
      if (visit[nx][ny] == -1){
        visit[nx][ny] = visit[cur.first][cur.second] + 1;
        fire.push({nx, ny});
      }
    }
  }
  /*for (int i = 0; i < R; i++){
    for (int j = 0; j < C; j++){
      cout << visit[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;*/

  int min;

  while(!J.empty()){
    pair<int, int> cur = J.front(); J.pop();
    cout << cur.first << " " << cur.second << endl;
    for (int i = 0; i < R; i++){
      for (int j = 0; j < C; j++){
        cout << Jvisit[i][j] << " ";
        }
        cout << endl;
      }
      cout << endl;
    for (int i = 0; i < 4; i++){
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];

      if (nx < 0 || nx >= R || ny < 0 || ny >= C){
        cout << cur.first << " " << cur.second << endl; 
        min = Jvisit[cur.first][cur.second] + 1;
        break;
      }

      if (Jvisit[nx][ny] > -2 && Jvisit[nx][ny] > visit[nx][ny]) {
        min = 0;
        break;
      }
      
      if (Jvisit[nx][ny] > -2 && Jvisit[nx][ny] <= visit[nx][ny]){
        if (Jvisit[nx][ny] <= -1){
          Jvisit[nx][ny] = Jvisit[cur.first][cur.second] + 1;
          J.push({nx, ny});
        }
      }
    }
  }
  if (min == 0) cout << "IMPOSSIBLE" << endl;
  else cout << min << endl;
}