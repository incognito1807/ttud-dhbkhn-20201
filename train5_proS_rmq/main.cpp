#include <bits/stdc++.h>
using namespace std;

const int Max = 1000005;
const int width = 21;

// đầu vào
int n, p;
int a[Max];

// cấu trúc dữ liệu
int k, z;
int m[Max][width];

// đầu ra
int res = 0;

void input() {
    cin >> n;
    for(int t = 0; t < n; t++)
        cin >> a[t];
    cin >> p;
}

void process() {
    for(int i = 0; i < n; i++)
        m[i][0] = a[i];

    for(int j = 1; (1 << j) <= n; j++)
        for(int i = 0; i + (1 << j) <= n; i++)
            m[i][j] = min(m[i][j - 1], m[i + (1 << (j - 1))][j - 1]);
    // for(int j = 0; j < 5; j++) {
    //     for(int i = 0; i < n; i++) {
    //         cout << m[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
}

int find(int i, int j) {
    k = log2(j-i+1);
    z = pow(2, k);
    return min(m[i][k], m[j-z+1][k]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    process();
    int i, j;
    for(int t = 0; t < p; t++) {
        cin >> i >> j;
        res += find(i, j);
        // cout << i << " " << j << " ";
        // cout << find(i, j) << endl;
    }
    cout << res;
    return 0;
}
