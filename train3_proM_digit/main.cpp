#include <bits/stdc++.h>
using namespace std;

//int t;
int n;
int a[8];
int d[10];
int cnt;

bool check() {
    if(a[1]*100+a[2]*10+a[3]-a[7]*100-62+a[4]*1000+a[5]*100+a[6]*10+a[3] == n)
        return true;
    else
        return false;
}

void Try(int k) {
    if(k == 8) {
        if(check())
            cnt++;
    } else {
        for(int i = 1; i <= 9; i++) {
            if(!d[i]) {
                d[i] = 1;
                a[k] = i;
                Try(k+1);
                d[i] = 0;
            }
        }
    }
}

int main() {
//    cin >> t;
//    for(int i = 0; i < t; i++) {
        cin >> n;
        cnt = 0;
        Try(1);
        cout << cnt << endl;
//    }
    return 0;
}
