#include <bits/stdc++.h>
using namespace std;

int calc(queue <pair <int, int>> Q, list<pair <int, int>> apple, list<pair <int, char>> dir, vector<vector<int>> board, int N){
  int sec = 0; //몇초가 지났는지

  Q.push({0,0}); //뱀 시작
  int nx = 0;
  int ny = 0;
  pair <int, int> direction;
  direction.first = 0;
  direction.second = 0;

  int dx[4] = {0, 1, 0, -1}; //우하좌상 (D기준 방향->)
  int dy[4] = {1, 0, -1, 0};

  bool conflict = false; //충돌 여부 저장
  while (!conflict){
    pair <int, int> cur = Q.back();
    int nx = cur.first + dx[direction.first];
    int ny = cur.second + dy[direction.second];
    for (const auto& a : dir){ //일정 초가 되면 방향이 바뀌는 부분
      if (a.first == sec){
        if (a.second == 'L') {
          if (direction.first == 0){
            direction.first = 3;
            direction.second = 3;
          }
          else{
            direction.first--;
            direction.second--;
          }
          nx = cur.first + dx[direction.first];
          ny = cur.second + dy[direction.second];
        }
        else if (a.second == 'D') {
          if (direction.first == 3){
            direction.first = 0;
            direction.second = 0;
          }
          else{
            direction.first++;
            direction.second++;
          }
          nx = cur.first + dx[direction.first];
          ny = cur.second + dy[direction.second];
          //cout << "바뀜" <<endl;
        }
      }
    }
    if (nx >= N || nx < 0 || ny >= N || ny < 0) {
      conflict = true;
      continue;
    }
    if (board[nx][ny] == 1) {
      conflict = true;
      continue;
    }
    if (board[nx][ny] == 2){
      board[nx][ny] = 1;
      Q.push({nx, ny});
      sec++;
    }
    if (board[nx][ny] == 0){
      board[nx][ny] = 1;
      cur = Q.front();
      board[cur.first][cur.second] = 0;
      Q.pop();
      Q.push({nx, ny});
      sec++;
    }
  }
  return sec;
}

int main(void){
  int N; //보드의 크기
  int K; //사과의 갯수
  int X; //방향 전환 정보 갯수

  list<pair <int, int>> apple; //사과 위치 정보
  int x, y;
  list<pair <int, char>> dir; //방향 전환 정보
  int time;
  char head;
  queue <pair <int, int>> Q; //뱀의 몸을 저장

  cin >> N;
  cin >> K;
  for (int i = 0; i < K; i++){
    cin >> x >> y;
    apple.push_back(make_pair(x - 1, y - 1));
  }
  cin >> X;
  for (int i = 0; i < X; i++){
    cin >> time >> head;
    dir.push_back(make_pair(time, head));
  }

  vector<vector<int>> board(N, vector<int>(N,0)); //사과 위치가 주어진 board

  for (const auto& ele : apple) { //사과 위치 map에 표시
    board[ele.first][ele.second] = 2;
  }

  int res;

  res = calc(Q, apple, dir, board, N);
  cout << res + 1;
}