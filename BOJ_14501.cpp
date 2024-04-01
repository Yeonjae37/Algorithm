#include <bits/stdc++.h>
using namespace std;

int calc(int T[], int P[], int N){
  int day[N+1];
  for (int i = 0; i <= N; i++){
    day[i] = i+1;
  }
  int max[N+1];
  for (int a = 0; a <= N; a++){
    max[a] = 0;
  }

  for (int i = 0; i <= N; i++){
    for (int j = 0; j < i; j++){
      if (day[j] + T[j] == day[i]){
        if (max[i] < (max[j] + P[j])){
          fill(max+i, max + N + 1, max[j] + P[j]);
        }
      }
    }
  }

  int temp = 0;
  for (int a = 0; a < N + 1; a++){
    if (temp < max[a]){
      temp = max[a];
    }
  }
  return temp;
}

int main(){
  int N;
  cin >> N;
  int T[N+1];
  int P[N+1];
  for (int i = 0; i < N; i++){
    cin >> T[i];
    cin >> P[i];
  }
  T[N] = 0;
  P[N] = 0;

  cout << calc(T, P, N);
}