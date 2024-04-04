#include <bits/stdc++.h>
using namespace std;

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
    int brute = tmp;
    for(int i = 0; i < 4; i++){
      if(brute % 2 == 1)
        cout << i;
      brute /= 2;
    }
    cout << "}\n";
  }
}