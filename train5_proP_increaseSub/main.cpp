#include <bits/stdc++.h>
using namespace std;

const int Max = 10005;

int test(int v[], int l, int r, int key) {
    while(r - l > 1) {
        int m = (r + l) / 2;
        if(v[m] >= key)
            r = m;
        else
            l = m;
    }
    return r;
}

int leng(int v[], int n) {
    if(n == 0)
        return 0;

    int a[n];
    int res = 1;

    a[0] = v[0];
    for(int i = 1; i < n; i++) {
        if(v[i] < a[0])
            a[0] = v[i];

        else if(v[i] > a[res - 1])
            a[res++] = v[i];
            a[test(a, -1, res - 1, v[i])] = v[i];
    }
    return res;
}

int main() {
    int v[Max];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    cout << leng(v, n);
    return 0;
}
