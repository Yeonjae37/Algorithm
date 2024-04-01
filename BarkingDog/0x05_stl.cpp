#include <bits/stdc++.h>
using namespace std;

int main(void){
  string line; //입력용
  stack<char> S;
  vector<string> ans;
  while (true){
    getline(cin, line);
    if (line == ".")
      break;
    for (auto a : line){
      if (a == '('){
        S.push('(');
      }
      else if (a == ')'){
        if (S.empty() == true){
          //cout << "no" << endl;
          ans.push_back("no");
          break;
        }
        else if (S.top() == '('){
          //cout << "yes" << endl;
          ans.push_back("yes");
          S.pop();
          break;
        }
        else if (S.top() != '('){
          //cout << "no" << endl;
          ans.push_back("no");
          break;
        }
      }

      else if (a == '['){
        S.push('[');
      }

      else if (a == ']'){
        if (S.empty() == true){
          //cout << "no" << endl;
          ans.push_back("no");
          break;
          }
        else if (S.top() == '['){
          //cout << "yes" << endl;
          ans.push_back("yes");
          S.pop();
          break;
        }
        else if (S.top() != '['){
          //cout << "no" << endl;
          ans.push_back("no");
          break;
        }
      }

      else if (a == '.'){
        //cout << "yes" << endl;
        ans.push_back("yes");
      }
    }

    if (!S.empty()) {
        //cout << "no" << endl;
          while (!S.empty()){
            S.pop();
          }
      }
  }
  for (auto& a : ans){
    cout << a << endl;
  }
}