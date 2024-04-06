#include <bits/stdc++.h>
using namespace std;

int S[20];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  string str;
  int m;
  cin >> m;
  while(m--){
    int n;
    cin >> str;
    if (str == "add"){
      cin >> n;
      S[n-1] = 1;
    }
    else if(str == "remove"){
      cin >> n;
      S[n-1] = 0;
    }
    else if(str == "check"){
      cin >> n;
      cout << S[n-1] << '\n';
    }
    else if(str == "toggle"){
      cin >> n;
      S[n-1] = 1 ^ S[n-1]; //XOR
    }
    else if(str == "all"){
      fill(S, S+20, 1);
    }
    else{
      fill(S, S+20, 0);
    }
  }
}