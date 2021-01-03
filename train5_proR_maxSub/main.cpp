#include <bits/stdc++.h>
using namespace std;

const int Max = 1000005;
int n, a[Max];
int sum = 0;
int res = -99999;
int t = -99999;

int max(int arr[]) {
    for(int i = 0; i < n; i++) {
        if(a[i] > t)
            t = a[i];
    }
    return t;
}

bool check() {
    int z = 0;
    for(int i = 0; i < n; i++)
        if(a[i] > 0)
            z++;
    if(z != 0)
        return true;
    else
        return false;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if(check()) {
        for(int i = 0; i <n; i++) {
            sum += a[i];
            if(sum > res)
                res = sum;
            if(sum < 0)
                sum = 0;
        }
        cout << res;
    } else
        cout << t;
    return 0;
}
