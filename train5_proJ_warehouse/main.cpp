#include <bits/stdc++.h>
using namespace std;

const int Max = 1005;
int n, T, d;
int a[Max];
int t[Max];
int dp[Max][Max];
int res = 0;

void input() {
    cin >> n >> T >> d;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> t[i];
}

void solve() {
    for(int i = 1; i <= n; i++)
        for(int k = t[i]; k <= T; k++) {
            for(int j = i-1; j >= max(0, i-d); j--)
                dp[i][k] = max(dp[i][k], dp[j][k-t[i]] + a[i]);
            res = max(res, dp[i][k]);
        }
    cout << res;
}

int main() {
    input();
    solve();
    return 0;
}
