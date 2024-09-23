#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> adj[10001]; //간선과 가중치 저장
int ans[10001]; //최단 거리 테이블
int city[10001];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

//first = node, second = cost
void dijkstra(int s) {
    pq.push({0, s});
    ans[s] = 0;

    while (!pq.empty()) {
        int cur_cost = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        // 현재 정점까지의 비용이 이미 최단 거리보다 크면 무시
        if (cur_cost > ans[cur_node]) continue;

        // 인접 노드 순회
        for (auto nxt : adj[cur_node]) {
            int nxt_node = nxt.first;
            int nxt_cost = nxt.second;

            // 더 짧은 경로를 발견하면 갱신
            if (ans[nxt_node] > cur_cost + nxt_cost) {
                ans[nxt_node] = cur_cost + nxt_cost;
                city[nxt_node] = cur_node;
                pq.push({ans[nxt_node], nxt_node});
            }
        }
    }
}

int main(void) {
  int n, m, s, e; 

  cin >> n; // 도시 개수 (도시가 node)
  cin >> m; // 버스 개수 (버스가 edge)

  fill(ans, ans + n + 1, INT_MAX);

  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    adj[u].push_back({v, w}); 
  }
  cin >> s >> e;

  dijkstra(s);

  cout << ans[e] << "\n";

  //경로 역추적 (도착점 -> 출발점)
  vector<int> path; //경로 저장용 
  int node = e; //도착점부터 시작!!
  while (node != s) { //출발점까지
    path.push_back(node); 
    node = city[node]; //부모 노드 추적 
    /*
    city[5] = 4면 node = 4로 갱신되고
    4번 도시로 이동해서 다시 경로 역추적
    */
  }
  path.push_back(node);

  reverse(path.begin(), path.end()); //역순으로 저장되어 있으므로 경로 뒤집기
  cout << path.size() << "\n";
  for (auto x : path) cout << x << ' ';
}