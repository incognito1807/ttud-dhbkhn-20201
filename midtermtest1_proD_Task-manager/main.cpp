#include <bits/stdc++.h>
using namespace std;

const int Max = 35;
int n, m, T;
int c[Max][Max];
int cnt[Max];
int res = 1e9;
int sum = 0;

void input() {
    cin >> n >> m >> T;
    for(int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++) {
            cin >> c[i][j];
        }
    }
    for(int i = 0; i < m; i++)
        cnt[i] = 0;
}

void Try(int k) {
    for(int i = 0; i < m; i++){
        if(cnt[i] < T && sum + c[k][i] < res) {
            cnt[i]++;
            sum += c[k][i];
            if(k == n-1){
                if(sum < res)
                    res = sum;
            } else
                Try(k+1);
            cnt[i]--;
            sum -= c[k][i];
        }
    }
}

int main() {
    input();
    Try(0);
    cout << res;
    return 0;
}
