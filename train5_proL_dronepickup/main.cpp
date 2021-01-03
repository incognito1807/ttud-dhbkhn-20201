#include <bits/stdc++.h>
using namespace std;

const int Max = 3005;
int n, K;
int c[Max];
int a[Max];
int dp[Max][105];
int res = 0;

void input() {
    cin >> n >> K;
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= K+1; j++)
            dp[i][j] = -1e9;
}

void solve() {
    dp[n][1] = c[n];
    for(int i = n-1; i >= 1; i--) {
        for(int k = 1; k <= K + 1; k++) {
            for(int j = i + 1; j <= min(i + a[i], n); j++)
                dp[i][k] = max(dp[i][k], dp[j][k - 1] + c[i]);
            res = max(res, dp[1][k]);
        }
    }

//    int D = 0;
//    for(int i = 1; i <= n; i++)
//        D = max(D, a[i]);
//    dp[1][1] = c[1];
//    for(int i = 2; i <= n; i++) {
//        for(int k = 1; k <= K+1; k++) {
//            for(int j = i-1; j >= max(0, i - D); j--) {
//                if(j + a[j] >= i)
//                    dp[i][k] = max(dp[i][k], dp[j][k - 1] + c[i]);
//            }
//            res = max(res, dp[n][k]);
//        }
//    }
    cout << res;
}

int main() {
    input();
    solve();
    return 0;
}
