#include <bits/stdc++.h>
using namespace std;

int main(){
  string str;
  cin >> str;
  int len = str.length();
  string alp = "abcdefghijklmnopqrstuvwxyz";
  int arr[26] = {0, };
  
  for (char e : str){
    for (char x : alp){
      if (e == x){
        int idx = alp.find(e);
        arr[idx]++;
      }
    }
  }
  
  for (int i : arr){
    cout << i << " ";
  }
}