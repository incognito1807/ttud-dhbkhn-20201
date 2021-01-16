#include <bits/stdc++.h>
using namespace std;

const int Max = 100005;
int t, n , k;
int a[Max];
int res;

void check(int a[], int n) {
    while(log(n)/log(2)) {
        if(n%2 == 0) {
            n /= 2;
            k = 0;
            for(int j = 0; j < n; j++) {
                a[j] = a[2*j] + a[2*j + 1];
                k = max(k, a[j]);
            }
            res += k;
        } else {
            n = n/2 + 1;
            k = 0;
            for(int j = 0; j < n-1; j++) {
                a[j] = a[2*j] + a[2*j + 1];
                k = max(k, a[j]);
            }
            a[n-1] = a[2*(n-1)];
            k = max(k, a[n-1]);
            res += k;
        }
    }
    cout << res << endl;
}

int main() {
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        for(int j = 0; j < n; j++)
            cin >> a[j];
        check(a, n);
    }
    return 0;
}
