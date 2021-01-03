#include <bits/stdc++.h>
using namespace std;

const int Max = 1000006;
int n, t, u;
int a[Max];
int z;                  // biến lưu giá trị nhập vào
int cnt;                // đếm số lượng phần tử có thể là đồi hoặc thung lũng
int f1, f2;             // biến lưu 2 giá trị trước đó để so sánh
int doi = 0, tl = 0;
int x;                  // biến lưu vị trí bắt đầu có 2 số khác nhau

int check(int f1, int f2, int z) {
    if(f2 < z && f1 < f2)
        return 4;
    else if(f2 > z && f1 > f2)
        return 3;
    else if(f2 > z && f1 < f2)
        return 2;
    else if(f2 < z && f1 > f2)
        return 1;
    else
        return 0;
}

void input() {
    cin >> n;
    cin >> t >> u;
    cnt = 2;
    x = 3;
    for(int i = 3; i <= n; i++) {
        if(t != u) {
            if(t < u) {
                a[1] = 1;
                a[2] = 2;
                f1 = t;
                f2 = u;
            } else if(t > u) {
                a[1] = 2;
                a[2] = 1;
                f1 = t;
                f2 = u;
            }
            break;
        } else if(t == u) {
            cin >> u;
            x++;
        }
    }
    if(x < n) {
        for(int i = x; i <= n; i++) {
            cin >> z;
            if(check(f1, f2, z) == 4) {
                f1 = f2;
                f2 = z;
                a[cnt] += 1;
            } else if(check(f1, f2, z) == 3) {
                f1 = f2;
                f2 = z;
                a[cnt] -= 1;
            } else if(check(f1, f2, z) == 2) {
                f1 = f2;
                f2 = z;
                cnt++;
                a[cnt] = a[cnt-1] - 1;
            } else if(check(f1, f2, z) == 1) {
                f1 = f2;
                f2 = z;
                cnt++;
                a[cnt] = a[cnt-1] + 1;
            }
        }
    } else if(x == n) {
        cin >> z;
        if(check(f1, f2, z) == 4) {
            f1 = f2;
            f2 = z;
            a[cnt] += 1;
        } else if(check(f1, f2, z) == 3) {
            f1 = f2;
            f2 = z;
            a[cnt] -= 1;
        } else if(check(f1, f2, z) == 2) {
            f1 = f2;
            f2 = z;
            cnt++;
            a[cnt] = a[cnt-1] - 1;
        } else if(check(f1, f2, z) == 1) {
            f1 = f2;
            f2 = z;
            cnt++;
            a[cnt] = a[cnt-1] + 1;
        }
    }
}

void solve() {
    // cout << cnt << endl;
    // for(int i = 1; i <= cnt; i++)
    //     cout << a[i] << " ";
    // cout << endl;
    // cout << x << endl;
    for(int i = 2; i < cnt; i++) {
        if(a[i] > a[i-1])
            doi = max(doi, min(a[i] - a[i-1], a[i] - a[i+1]));
        else
            tl = max(tl, min(a[i-1] - a[i], a[i+1] - a[i]));
    }
    cout << doi << " " << tl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
    return 0;
}
