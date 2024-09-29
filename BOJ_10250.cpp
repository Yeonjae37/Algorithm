#include <bits/stdc++.h>
using namespace std;

int main(void){
  int T, h, w;
  cin >> T;
  for (int i = 0; i < T; i++){
    int H, W, N;
    cin >> H >> W >> N;

    h = N % H; // 몇번째 층
    w = N / H; //몇번째 방

    if (h == 0) {
      h = H;
      w--;
    }
    w++; 

    if (w >= 10) cout << h << w << "\n"; 
    else cout << h << "0" << w << "\n";
  }
}