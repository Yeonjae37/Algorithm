#include <bits/stdc++.h>
using namespace std;

vector<int> A;
vector<int> A_sort;
vector<vector<pair<int, int>>> adj;
/*
adj[1] = {{2, 4}, {4, 10}}
adj[2] = {{3, 3}}
adj[3] = {{4, 2}}
*/
map<vector<int>, int> ans; // key -> 배열, value -> cost
priority_queue<pair<int, vector<int>>, vector<pair<int,vector<int>>>, greater<pair<int,vector<int>>>> pq;

void dijkstra(int N){
  pq.push({0, A});
  ans[A] = 0;
  while(!pq.empty()){
    int cur_cost = pq.top().first;
    vector<int> cur_array = pq.top().second;
    pq.pop();

    if (cur_cost > ans[cur_array]) continue;
    for (int i = 1; i <= N; i++) { //배열의 모든 인덱스에서 교환할 수 있는 인덱스들 확인
      for (auto nxt : adj[i]) {  //adj[i] -> i 인덱스 원소와 교환할 인덱스와 cost
        int l = i;  
        int r = nxt.first; // 교환 대상
        int nxt_cost = nxt.second;

        vector<int> new_array = cur_array; // 새로운 배열을 만들기 위한 복사
        swap(new_array[l], new_array[r]);  // 새로운 배열에서 두 원소 자리 변경

        // map.find(key) -> 존재하지 않으면 map.end() 반횐
        if (ans.find(new_array) == ans.end() ||  // ans에 없었던 array이거나
              ans[new_array] > cur_cost + nxt_cost) { // ans에 있지만 기존 비용이 현재 비용보다 크면
          ans[new_array] = cur_cost + nxt_cost;
          pq.push({ans[new_array], new_array});
        }
      }
    }
  }
}

int main(void){
  int N, M; //N = 배열 A의 길이, M = 조작의 개수
  cin >> N;
  A.resize(N + 1);
  A_sort.resize(N + 1);
  adj.resize(N + 1);

  for (int i = 1; i <= N; i++) {
    cin >> A[i];
    A_sort[i] = A[i];
  }

  sort(A_sort.begin() + 1, A_sort.end());

  cin >> M;
  for (int i = 0; i < M; i++){
    int l, r, c;
    cin >> l >> r >> c;
    adj[l].push_back({r, c});
  } 

  dijkstra(N);
  
  if (ans.find(A_sort) != ans.end()) cout << ans[A_sort] << "\n";
  else cout << "-1" << "\n";

  return 0;
}