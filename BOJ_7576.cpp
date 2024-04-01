#include <bits/stdc++.h>
using namespace std;
//정수 1 : 익은 토마토
//정수 0 : 익지 않은 토마토
//정수 -1 : 토마토가 들어있지 않은 칸


int main(void){
  int N; //세로
  int M; //가로
  queue <pair <int, int>> Q;
  cin >> M;
  cin >> N;
  vector<vector<int>> stor(N, vector<int>(M,0)); //토마토를 보관하는 창고
  vector<vector<int>> stor(N, vector<int>(M,-1)); //익은 날짜를 저장

  for (int i = 0; i < N; i++){ //토마토 첫 상태 입력
    for (int j = 0; j < M; j++){
      cin >> stor[i][j];
    }
  }
  for (int i = 0; i < N; i++){ //토마토 첫 상태 입력
    for (int j = 0; j < M; j++){
      if (stor[i][j] == 1) Q.push({i, j}); // 익은 경우의 토마토 push
    }
  }
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};

  while(!Q.empty()){
    pair <int, int> cur = Q.front(); Q.pop();
    
  }
}