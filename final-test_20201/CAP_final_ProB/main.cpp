#include <bits/stdc++.h>
using namespace std;

const int Max = 100005;
int t, n, k;
int a[Max];
int c[Max][2];
bool flag = false;
int res;

void check(int a[], int n) {
    k = 1;
    res = 0;
    c[0][0] = a[0];
    c[0][1] = 1;
    for(int j = 1; j < n; j++) {
        for(int h = 0; h < k; h++) {
            if(a[j] == c[h][0]+1) {
                c[h][0] = a[j];
                c[h][1]++;
            } else {
                c[k][0] = a[j];
                c[k][1] = 1;
                flag = true;
            }
        }
        if(flag == true) {
            k++;
            flag = false;
        }
    }
    for(int j = 0; j < k; j++)
        res = max(res, c[j][1]);
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
