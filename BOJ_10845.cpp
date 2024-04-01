#include <bits/stdc++.h>
using namespace std;

queue<int> Q;

void push(int X){
  Q.push(X);
}

void pop(){
  if (Q.empty()) cout << -1 << endl;
  else {
    cout << Q.front() << endl;
    Q.pop();
  }
}

void size(){
  cout << Q.size() << endl;
}

void empty(){
  if (Q.empty()) cout << 1 << endl;
  else cout << 0 << endl;
}

void front(){
  if (Q.empty()) cout << -1 << endl;
  else cout << Q.front() << endl;
}

void back(){
  if (Q.empty()) cout << -1 << endl;
  else cout << Q.back() << endl;
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