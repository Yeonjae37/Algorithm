#include <bits/stdc++.h>
using namespace std;

void func(const vector<int>& num, vector<int>& visited, vector<int>& ans, int depth, int M) {
  if (depth == M) { //M만큼 방문했다면
    for (auto a : ans) { //ans 출력
      cout << a << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = 0; i < num.size(); i++) { //수열 모두 방문했는지 체크
    if(visited[i] == 1) continue; //방문했다면 취소

    visited[i] = 1; //방문했다고 체크
    ans[depth] = num[i]; //현재 위치에 num[i] 넣기
    func(num, visited, ans, depth + 1, M); //depth에 +1 해서 재귀
    visited[i] = 0; //방문 체크한거 취소
  }
}

int main(void) {
  int N, M;
  ios::sync_with_stdio(0);
	cin.tie(0);

  cin >> N >> M;
  vector<int> num(N, 0); //수열
  vector<int> visited(N, 0); //방문 여부
  vector<int> ans(M, 0); //답

  for (int i = 0; i < N; i++) {
    cin >> num[i];
  }
  sort(num.begin(), num.end()); //수열 오름차순 정렬
  func(num, visited, ans, 0, M); 
}