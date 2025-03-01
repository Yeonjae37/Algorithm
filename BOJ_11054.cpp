#include <bits/stdc++.h>
using namespace std;

int num[1000];

void DP(int N) {
    vector<int> left(N, 1);
    vector<int> right(N, 1);

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (num[j] < num[i] && left[i] < left[j] + 1) {
                left[i] = left[j] + 1;
            }
        }
    }

    for (int i = N - 2; i >= 0; i--) {
        for (int j = N - 1; j > i; j--) {
            if (num[j] < num[i] && right[i] < right[j] + 1) {
                right[i] = right[j] + 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, left[i] + right[i] - 1);
    }

    cout << ans << endl;
}

int main(void) {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    DP(N);
}