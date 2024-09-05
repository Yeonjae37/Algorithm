#include <bits/stdc++.h>
using namespace std;

int main() {
  int M, N, input;
  cin >> M >> N;
  vector<int> snacks;
  for (int i = 0; i < N; i++) {
    cin >> input;
    snacks.push_back(input);
  }

  sort(snacks.begin(), snacks.end());

  int left = 1;
  int right = snacks[N - 1];
  int ans = 0;

  while (left <= right) {
    int mid = (left + right) / 2;

    int cnt = 0;
      for (int i = 0; i < N; i++) {
        cnt += snacks[i] / mid;
      }

      if (cnt >= M) {
        left = mid + 1;
        ans = mid;
      }

      else {
        right = mid - 1;
      }
  }

  cout << ans << "\n";

  return 0;
}