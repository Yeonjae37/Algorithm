#include <bits/stdc++.h>
using namespace std;

deque<int> DQ;

void push_front(int num){
  DQ.push_front(num);
}

void push_back(int num){
  DQ.push_back(num);
}

void pop_front(){
  if(DQ.empty()) cout << -1 << endl;
  else {
    cout << DQ.front() << endl;
    DQ.pop_front();
  }
}

void pop_back(){
  if(DQ.empty()) cout << -1 << endl;
  else {
    cout << DQ.back() << endl;
    DQ.pop_back();
  }
}

void size(){
  cout << DQ.size() << endl;
}

void empty(){
  if(DQ.empty()) cout << 1 << endl;
  else cout << 0 << endl;
}

void front(){
  if(DQ.empty()) cout << -1 << endl;
  else cout << DQ.front() << endl;
}

void back(){
  if(DQ.empty()) cout << -1 << endl;
  else cout << DQ.back() << endl;
}

int main(void){
  int N, num;
  cin >> N;
  string str;
  for (int i = 0; i < N; i++){
    cin >> str;
    if (str == "push_front"){
      cin >> num;
      push_front(num);
    }
    else if (str == "push_back"){
      cin >> num;
      push_back(num);
    }
    else if (str == "pop_front") pop_front();
    else if (str == "pop_back") pop_back();
    else if (str == "size") size();
    else if (str == "empty") empty();
    else if (str == "front") front();
    else if (str == "back") back();
  }
}