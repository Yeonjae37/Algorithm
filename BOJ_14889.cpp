#include <bits/stdc++.h>
using namespace std;

int final = INT_MAX;

int Comb(vector<vector<int>>& work, vector<int>& link, int cur, int N, vector<int>& temp) {
  int result = 0;
  if (temp.size() == 2) {
    result = work[temp[0] - 1][temp[1] - 1] + work[temp[1] - 1][temp[0] - 1];
    return result;
  }
  int sum_result = 0;
  for (int n = cur; n < N/2; n++) { 
    temp.push_back(link[n]);
    sum_result += Comb(work, link, n + 1, N, temp);
    temp.pop_back();
  }
  return sum_result;
}

void Combination(vector<vector<int>> &work, vector<int>& link, vector<int>& start, vector<int>& team, int arr[], int depth, int N) {
  vector<int> temp;
  vector<int> temp2;
  int link_work;
  int start_work;
  if (team.size() == N/2) {
    for (int i : team) {
      link.push_back(i);
    }
    for (int j = 1; j <= N; j++) {
      if (find(team.begin(), team.end(), j) == team.end()) {
      start.push_back(j);
      }
    }
    link_work = Comb(work, link, 0, N, temp);
    start_work = Comb(work, start, 0, N, temp2);

    int diff = abs(link_work - start_work);
    final = min(final, diff);

    for (int p : link) {
      link.pop_back();
    }
    for (int v : start) {
      start.pop_back();
    }

    return;
  }
  for (int n = depth; n < N; n++) {
    team.push_back(arr[n]);
    Combination(work, link, start, team, arr, n + 1, N);
    team.pop_back();
  }
}

int main() {
  int N;
  cin >> N;
  int arr[N];
  vector<vector<int>> work(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    arr[i] = i + 1; 
    for (int j = 0; j < N; j++) {
      cin >> work[i][j];
    }
  }
  vector<int> link;
  vector<int> start;
  vector<int> team;
  Combination(work, link, start, team, arr, 0, N);
  cout << final << endl;
  
}
