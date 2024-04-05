#include <bits/stdc++.h>
using namespace std;

int N;
int K;
int arr[100002];

int main(void){
  queue <int> Q;
  fill(arr, arr+100001, -1);

  cin >> N;
  Q.push(N);
  arr[N] = 0;

  cin >> K;

  int dx[3] = {-1,1,2};

  int n;

  while(arr[K] == -1){
    int cur = Q.front(); Q.pop();
    for (int i = 0; i < 3; i++){
      if (i == 2) n = cur*dx[i];
      else n = cur+dx[i];

      if (n < 0 || n > 100000) continue;
      if(arr[n] != -1) continue;
      arr[n] = arr[cur] + 1;
      Q.push(n);
    }
  }
  cout << arr[K];
}