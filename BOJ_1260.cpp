#include <bits/stdc++.h>
using namespace std;

queue<int> Q;
vector<int> graph[1002];
bool visited[1002];
bool visited2[1002];

void DFS(int cur){
  visited[cur] = true;
  cout << cur << " ";
  for (int i = 0; i < graph[cur].size(); i++){
    int next = graph[cur][i];
    if(!visited[next]) DFS(next);
  }
}

void BFS(){
  while(!Q.empty()){
    int cur = Q.front();
    Q.pop();
    cout << cur << " ";
    for (int i = 0; i < graph[cur].size(); i++){
      int next = graph[cur][i];
      if(!visited2[next]) {
        visited2[next] = true;
        Q.push(next);
      }
    }
  }
}

int main(void){
  int N; //정점의 개수
  int M; //간선의 개수
  int V; //탐색을 시작할 정점의 번호

  cin >> N >> M >> V;

  for (int i = 0; i < M; i++){
    int X,Y;
    cin >> X >> Y;
    graph[X].push_back(Y);
    graph[Y].push_back(X);
  }

  for (int i = 1; i <= N; i++)
    sort(graph[i].begin(), graph[i].end());

  DFS(V);
  cout << endl;

  Q.push(V);
  visited2[V] = true;
  BFS();

  return 0;
}