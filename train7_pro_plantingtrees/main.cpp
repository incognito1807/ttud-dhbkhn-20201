#include <bits/stdc++.h>
using namespace std;

const int Max = 1e6+1;
int n;
int a[Max];
int res = 0;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    for(int i = 0; i < n; i++)
        res = max(res, a[i]);
    cout << res+2;
    return 0;
}
