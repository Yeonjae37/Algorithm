#include <bits/stdc++.h>
using namespace std;
vector<int> num(100002, 0);
int ans = 0;

int main(void) {
  int n;
  cin >> n;
  
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
  }
  vector<int> vec(n+1, 0);
  vec[1] = num[1];

  for (int i = 2; i <= n; i++) {
    if (num[i] > (vec[i - 1] + num[i])) {
      vec[i] = num[i];
    }
    else vec[i] = vec[i - 1] + num[i];
  }

  int ans = *max_element(vec.begin()+1, vec.end());

  cout << ans;
}