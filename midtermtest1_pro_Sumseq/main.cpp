#include <bits/stdc++.h>
using namespace std;

const int Max = 100005;
int n, m, M;
int a[Max];
int sum;
int cnt = 0;

void input() {
    cin >> n >> m >> M;
    for(int i = 0; i < n; i++)
        cin >> a[i];
}

void solve() {
    for(int i = 0; i < n; i++) {
        sum = 0;
        for(int j = i; j < n; j++) {
            if(sum <= M && sum >= m)
                cnt++;
            sum = sum + a[j];
        }
        if(sum <= M && sum >= m)
            cnt++;
    }
    cout << cnt;
}

int main() {
    input();
    solve();
    return 0;
}
