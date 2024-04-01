#include <bits/stdc++.h>
using namespace std;

int func2(int arr[], int& len){
  int occur[101] = {};
  for (int i = 0; i < len; i++){
    if(occur[100-arr[i]] == 1)
      return 1;
    occur[arr[i]] = 1;
  }
  return 0;
}

int main(){
  int N;
  cin >> N;
  int arr[N];
  for (int i = 0; i < N; i++){
    cin >> arr[i];
  }

  cout << func2(arr, N);
}