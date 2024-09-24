#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[1001];
int ans[1001];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

void dijkstra(int s){
  pq.push({0,s});
  ans[s] = 0;
  
  while(!pq.empty()) {
    int cur_cost = pq.top().first;
    int cur_node = pq.top().second;
    pq.pop();

    if (cur_cost > ans[cur_node]) continue;

    for (auto nxt : adj[cur_node]) {
      int nxt_cost = nxt.first;
      int nxt_node = nxt.second;

      if (ans[nxt_node] > cur_cost + nxt_cost){
        ans[nxt_node] = cur_cost + nxt_cost;
        pq.push({ans[nxt_node], nxt_node});
      }
    }
  }
}

int main(void) {
  int N, M; //도시 개수 N(node), 버스 개수 M(edge)

  cin >> N;
  cin >> M;

  fill(ans, ans + N + 1, INT_MAX);

  for(int i = 1; i <= M; i++) {
    int u, v, w;

    cin >> u >> v >> w;
    adj[u].push_back({w, v});
  }

  int s, e;
  cin >> s >> e;

  dijkstra(s);

  cout << ans[e] << "\n";
}