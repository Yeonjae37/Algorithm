#include<bits/stdc++.h>
using namespace std;

int check(string result){
  int middle = result.size() / 2;
  string temp1, temp2;
  if (result.size() % 2 == 1) { //홀수
    temp1 = result.substr(0, middle);
    temp2 = result.substr(middle+1, result.size());
  }
  else {
    temp1 = result.substr(0, middle);
    temp2 = result.substr(middle, result.size());
  }
  reverse(temp2.begin(), temp2.end());
  if (temp1 == temp2) return 1;
  else return 0;
}

int calc(int num){
  for (int i = 2; i <= 64; i++){
    int cur_num = num;
    string temp = "";
    while (cur_num > 0){
      int remain = cur_num % i;
      if (remain < 10){//숫자면
        temp += (char)(remain + '0');
      } 
      else {
        temp += (char)(remain - 10 + 'A');
      }
      cur_num = cur_num / i; //몫 계산
    }
    reverse(temp.begin(), temp.end()); //뒤집어!
    //cout << "i-" << i << " : " <<  temp << "\n";
    if (check(temp) == 1) return 1;
  }
  return 0;
}

int main(void){
  int T; cin >> T;
  while(T--){
    int num; cin >> num;
    cout << calc(num) << "\n";
  }
}