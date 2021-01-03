#include <bits/stdc++.h>
using namespace std;

int n;
int a[9];
int d[10];
int cnt;

bool check() {
    if(a[1]*1000+a[2]*100+a[3]*10+a[4]+a[3]*10000+a[5]*1000+a[6]*100+a[7]*10+a[4] == n && a[1] != 0 && a[3] != 0)
        return true;
    else
        return false;
}

void Try(int x) {
    if(x == 8) {
        if(check())
            cnt++;
    } else {
        for(int i = 0; i <= 9; i++) {
            if(!d[i]) {
                d[i] = 1;
                a[x] = i;
                Try(x+1);
                d[i] = 0;
            }
        }
    }
}

int main()
{
    cin >> n;
    Try(1);
    cout << cnt;
    return 0;
}
