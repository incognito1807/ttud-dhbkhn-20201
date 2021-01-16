#include <bits/stdc++.h>
using namespace std;

const int Max = 105;
int t, n, m;
int a[Max], b[Max];
int res;

void input(int a[], int n) {
    // nhập mảng
    for(int j = 0; j < n; j++)
        cin >> a[j];
    // loại bỏ các phần tử trùng nhau trong dãy
    sort(a, a+n);
    for(int j = 0; j < n-1; j++)
        if(a[j] == a[j+1])
            a[j] = 0;
}

void solve(int a[], int b[], int n, int m) {
    res = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i] == b[j] && a[i] != 0 && b[j] != 0)
                res++;
    cout << res << endl;
}

int main() {
    cin >> t;
    for(int k = 0; k < t; k++) {
        cin >> n;
        input(a, n);
        cin >> m;
        input(b, m);

        // tính toán
        solve(a, b, n, m);
    }
    return 0;
}
