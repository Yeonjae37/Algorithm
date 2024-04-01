#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string word;
  list<char> sentence = {};
  int M;
  string str;

  getline(cin, word);
  for (char &ch : word) {
    sentence.push_back(ch);
  }

  list<char>::iterator cursor = sentence.end();

  cin >> M;
  for (int i = 0; i <= M; i++){
    getline(cin, str);
    if (str.front() == 'L'){
      if (cursor != sentence.begin()){
        cursor--;
      }
    }
    else  if (str.front() == 'D'){
      if (cursor != sentence.end()){
        cursor++;
      }
    }
    else  if (str.front() == 'B'){
      if (cursor != sentence.begin()){
        cursor--;
        cursor = sentence.erase(cursor);
      }
    }
    else  if (str.front() == 'P'){
      sentence.insert(cursor, str.back());
    }
  }
  for(list<char>::iterator it = sentence.begin(); it != sentence.end(); it++)
  cout << *it;
}