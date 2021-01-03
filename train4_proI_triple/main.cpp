#include <bits/stdc++.h>
using namespace std;

const int Max = 5005;
int n, k;
int a[Max];

void input() {
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
}

int check(int z, int d, int c) {
    int m = (d+c) / 2;
    int cnt = 0;
    if(d > c)
        return 0;
    else if(d == c) {
        if(z == a[d])
            return 1 + check(z, d, m-1) + check(z, m+1, c);
        else
            return 0;
    } else {
        if(a[m] == z)
            return 1 + check(z, d, m-1) + check(z, m+1, c);
        else if(a[m] > z)
            return check(z, d, m-1);
        else
            return check(z, m+1, c);
    }
}

void solve() {
    sort(a, a+n);
    int res = 0;
    for(int i = 0; i < n-2; i++)
        for(int j = i+1; j < n-1;j++){
            int z = k - a[i] - a[j];
            res += check(z, j+1, n-1);
    }
    cout << res;
}

int main() {
    input();
    solve();
    return 0;
}
