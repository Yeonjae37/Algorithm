#include <bits/stdc++.h>
using namespace std;

const int MX = 10000005;
int dat[MX];
int pos = 0; //pos는 원소가 추가될 때 삽입해야하는곳.

void push(int x){
  dat[pos++] = x;
}

void pop(){
  pos--;
  //pos번지에 있는 값 자체는 굳이 삭제하지 않아도 괜찮음. 
  //왜냐하면 나중에 push가 발생하면 어차피 그 때 들어올 값으로 덮어써지기 때문.
}

int top(){
  return dat[pos-1];
}

void test(){
  
}

int main(void) {
  test();
}