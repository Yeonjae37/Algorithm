#include <bits/stdc++.h>
using namespace std;

int N;
int arr[12];
int op[4];
int max_res = INT_MIN;
int min_res = INT_MAX;

void DFS(int x, int res){
	if (x == N - 1){
		max_res = max(max_res, res);
		min_res = min(min_res, res);
	}

	for (int i = 0; i < 4; i++){
		if (op[i] > 0) {
			op[i]--;

			if (i == 0) {
				DFS(x + 1, res + arr[x + 1]);
			}
			else if (i == 1) {
				DFS(x + 1, res - arr[x + 1]);
			}
			else if (i == 2) {
				DFS(x + 1, res * arr[x + 1]);
			}	
			else if (i == 3) {
				DFS(x + 1, res/ arr[x + 1]);
			}
			op[i]++;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++){
		cin >> op[i];
	}

	DFS(0, arr[0]);

	cout << max_res << '\n';
	cout << min_res << '\n';

	return 0;
}