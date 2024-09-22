#include <bits/stdc++.h>
using namespace std;

/*
최소힙 만드는 법
큐에서 가장 작은 값을 먼저 처리하려면 원래 값에서 부호를 바꿔서 음수로 저장하면 됨.
이 코드의 경우 pair 를 사용하므로 first만 -절대값
*/

priority_queue<pair<int,int>> pq;
vector<pair<int,int>> adj[20001]; //간선과 가중치 저장
int ans[300001]; //최단 거리 테이블
const int INF = 1e9+10;

void dijkstra(int S) {
  pq.push({0, S});
  ans[S] = 0; //시작점 cost 0으로 세팅

  // first = cost, second = 정점
  while(!pq.empty()) {
    int cur_cost = -pq.top().first; //음수로 만들어져있으니까 양수로 다시 만들기
    int cur_edge = pq.top().second;
    pq.pop();

    if (cur_cost > ans[cur_edge]) continue; //먼저 확인

    for (auto nxt : adj[cur_edge]) { //인접 노드 순회
      int next_cost = nxt.first;
      int next_edge = nxt.second;

      //가중치가 더 작게 나오면 업데이트
      if (ans[next_edge] > cur_cost + next_cost) { 
        ans[next_edge] = cur_cost + next_cost;
        pq.push({-ans[next_edge], next_edge}); // 
      }
    }
  }
}

int main(void) {
  int V, E, S; //정점의 개수 V, 간선의 개수 E, 시작점 S

  cin >> V >> E;
  cin >> S;

  fill(ans, ans+V+1, INF); //INFINITE로 초기화

  for (int i = 1; i <= E; i++){
    int u, v, w; //u에서 v로 가는 가중치 w
    cin >> u >> v >> w;

    adj[u].push_back({w,v}); 
  }

  dijkstra(S);

  for (int i = 1; i <= V; i++) {
    if(ans[i] == INF) cout << "INF\n";
    else cout << ans[i] << "\n";
  }
}