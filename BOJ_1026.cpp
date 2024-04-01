#include <bits/stdc++.h>
using namespace std;

int final = INT_MAX;

void sort(vector<int> &A, vector<int> &B, int N, int sum){
  int temp;
  for (int i = 0; i < (A.size() - 1); i++){
    for (int j = 0; j < (A.size() - 1 - i); j++){
      if (A[j] > A[j+1]){
        temp = A[j];
        A[j] = A[j+1];
        A[j+1] = temp;
      }
    }
  }
  for (int i = 0; i < (B.size() - 1); i++){
    for (int j = 0; j < (B.size() - 1 - i); j++){
      if (B[j] < B[j+1]){
        temp = B[j];
        B[j] = B[j+1];
        B[j+1] = temp;
      }
    }
  }
  int result = 0;
  for (int i = 0; i < N; i++){
    result += A[i] * B[i];
  }
  cout << result;
}

int main(void) {
  int N;
  cin >> N;
  int sum = 0;
  vector<int> A(N);
  vector<int> B(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  for (int j = 0; j < N; j++){
    cin >> B[j];
  }
  sort(A, B, N, sum);
}