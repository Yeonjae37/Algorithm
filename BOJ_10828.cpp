#include <bits/stdc++.h>
using namespace std;

stack<int> S;

void push(int X){
  S.push(X);
}

void pop(){
  if(S.empty()) cout << "-1" << endl;
  else {
    cout << S.top() << endl;
    S.pop();
  }
}

void size(){
  cout << S.size() << endl;
}

void empty(){
  if(S.empty()) cout << "1" << endl;
  else cout << "0" << endl;
}

void top(){
  if(S.empty()) cout << "-1" << endl;
  else cout << S.top() << endl;
}

int main(void) {
  int num;
  int X;
  string str;
  cin >> num;
  for (int i = 0; i < num; i++){
    cin >> str;
    if (str == "push"){
      cin >> X;
      push(X);
    }
    else if (str == "pop") pop();
    else if (str == "size") size();
    else if (str == "empty") empty();
    else if (str == "top") top();
  }
}