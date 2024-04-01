#include <bits/stdc++.h>
using namespace std;
//배열 버전

const int MX = 1000005;
int dat[MX];
int head = 0, tail = 0;

void push(int X){
  dat[tail++] = X;
}

void pop(){
  if ((tail - head) == 0) cout << -1 << endl;
  else {
    cout << dat[head] << endl;
    head++;
  }
}

void size(){
  cout << tail - head << endl;
}

void empty(){
  if ((tail - head) == 0) cout << 1 << endl;
  else {
    cout << 0 << endl;
  }
}

void front(){
  if ((tail - head) == 0) cout << -1 << endl;
  else {
    cout << dat[head] << endl;
  }
}

void back(){
  if ((tail - head) == 0) cout << -1 << endl;
  else {
    cout << dat[tail - 1] << endl;
  }
}

int main(){
  int num;
  string str;
  int X;
  cin >> num;
  for (int i = 0; i < num; i++){
    cin >> str;
    if (str == "push"){
      cin >> X;
      push(X);
    }
    else if (str == "pop"){
      pop();
    }
    else if (str == "size"){
      size();
    }
    else if (str == "empty"){
      empty();
    }
    else if (str == "front"){
      front();
    }
    else if (str == "back"){
      back();
    }   
  }
}