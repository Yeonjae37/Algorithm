#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[1001];
vector<pair<int,int>> adj_reverse[1001];
int ans_go[1001]; //갈때 cost
int ans_return[1001]; //올때 cost
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

void dijkstra(int s, int dist[], vector<pair<int, int>> city[]) {
  pq.push({0, s});
  dist[s] = 0;

  while(!pq.empty()) {
    int cur_cost = pq.top().first;
    int cur_edge = pq.top().second;
    pq.pop();

    if (cur_cost > dist[cur_edge]) continue;

    for (auto nxt : city[cur_edge]){
      int nxt_edge = nxt.first;
      int nxt_cost = nxt.second;

      if (dist[nxt_edge] > cur_cost + nxt_cost) {
        dist[nxt_edge] = cur_cost + nxt_cost;
        pq.push({dist[nxt_edge], nxt_edge});
      }
    }
  }
}

int main(void) {
  int N, M, X; //N명의 학생(=마을), M개의 도로, 모일 마을 X
  
  cin >> N >> M >> X;
  fill(ans_go, ans_go+N+1, INT_MAX);
  fill(ans_return, ans_return+N+1, INT_MAX); 
  
  for (int i = 1; i <= M; i++) {
    int A, B, E;
    cin >> A >> B >> E; //출발 도시 A, 도착 도시 B, cost E

    adj[A].push_back({B, E}); 
    adj_reverse[B].push_back({A, E}); //모든 노드에서 X로 가는 경우를 위한 reverse
  }

  dijkstra(X, ans_go, adj_reverse);
  dijkstra(X, ans_return, adj);

  int temp = 0;
  for (int i = 1; i <= N; i++) {
    if (temp < ans_go[i] + ans_return[i]) {
      temp = ans_go[i] + ans_return[i];
    }
  }
  cout << temp << "\n";
}