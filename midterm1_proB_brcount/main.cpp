#include <bits/stdc++.h>
using namespace std;

const int Max = 1005;
const int e = 1e9+7;

int dp[Max][Max];

int main() {
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= n; j++) {
            if(s[i] == '(' && j >= 1)
                dp[i][j] = dp[i - 1][j - 1];
            if(s[i] == ')')
                dp[i][j] = dp[i - 1][j + 1];
            if(s[i] == '?') {
                if(j >=1)
                    dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j - 1]) % e;
                else
                    dp[i][j] = (dp[i - 1][j + 1] + 0) % e;
            }
        }
    cout << dp[n][0];
    return 0;
}
