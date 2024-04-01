#include <bits/stdc++.h>
using namespace std;

int main(void){
  string line; //입력용
  vector<string> ans;
  while (true){
    getline(cin, line);
    if (line == ".") break;
    stack<char> S;
    bool truth = true; 
    for (auto a : line){
      if (a == '(' || a == '['){
        S.push(a);
      }

      else if (a == ')'){
        if (S.empty() == true){
          truth = false;
          break;
        }
        else if (S.top() != '('){
          truth = false;
          break;
        }
        S.pop();
      }

      else if (a == ']'){
        if (S.empty() == true){
          truth = false;
          break;
          }
        else if (S.top() != '['){
          truth = false;
          break;
        }
        S.pop();
      }
    }
    if (!S.empty()) truth = false;

  cout << (truth ? "yes" : "no") << endl;
  }
}