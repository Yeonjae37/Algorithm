#include <bits/stdc++.h>
using namespace std;

string str;

void separate(string str){
  int ans = 0;
  vector<int> vec(str.size());
  stack<int> S;
  int num = str.size();
  for (int i = 0; i < num; i++){
    if (str[i] == '('){
      S.push(i);
    }
    else if (str[i] == ')'){
      if (str[i - 1] == '(') {
        S.pop();
        ans += S.size();
      }
      else {
        S.pop();
        ans++;
      }
    }
  }
  cout << ans;
  return;
}

int main(void){
  char a;
  int num;
  do {
    cin >> str;

  } while (getc(stdin) == ' ');

  separate(str);
}