#include <bits/stdc++.h>
using namespace std;

//{0, 1, 2, 3}의 모든 부분집합을 출력하기

bool isused[4];
void func(int k){
  if(k == 4){
    cout << "{";
    for(int  i = 0; i < 4; i++){
      if(isused[i])
        cout << i;
    }
    cout << "}\n";
    return;
  }
  //k를 선택하지 않는 경우
  func(k + 1);

  //k를 선택하는 경우
  isused[k] = true;
  func(k + 1);
  isused[k] = false;
}

void func2(){
  for(int tmp = 0; tmp < 16; tmp++){
    cout << "{";
    int brute = tmp; // 현재 숫자를 brute 변수에 저장
    for(int i = 0; i < 4; i++){ // 0부터 3까지의 각 숫자에 대해
      if(brute % 2 == 1) //LSB가 1인지 확인
        cout << i;
      brute /= 2; // 2를 나누는건 한자리씩 오른쪽 비트로 이동하는 효과를 가짐. 즉 다음 비트를 검사할 준비
    }
    cout << "}\n";
  }
}

/*
tmp = 0 (0000 이진수): 부분집합은 {} (공집합)
tmp = 1 (0001 이진수): 부분집합은 {0}
tmp = 2 (0010 이진수): 부분집합은 {1}
tmp = 3 (0011 이진수): 부분집합은 {0, 1}
tmp = 4 (0100 이진수): 부분집합은 {2}
tmp = 5 (0101 이진수): 부분집합은 {0, 2}
tmp = 6 (0110 이진수): 부분집합은 {1, 2}
tmp = 7 (0111 이진수): 부분집합은 {0, 1, 2}
*/

void func3() {
  for(int tmp = 0; tmp < 16; tmp++){
    cout << "{";
    for(int i = 0; i < 4; i++){
      if(tmp & (1 << i)) // 0이 아닐 경우 참
        cout << i;
    }
    cout << "}\n";
  }
}

int main(void) {
    func2(); // 재귀 함수 시작
    return 0;
}