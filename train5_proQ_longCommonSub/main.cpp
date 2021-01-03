#include <bits/stdc++.h>
using namespace std;

int lcs(int *a, int *b, int n, int m) {
    bool bi;
    int L[2][m + 1];
    for(int i = 0; i <= n; i++) {
        bi = i & 1;
        for(int j = 0; j <= m; j++) {
            if(i == 0 || j == 0)
                L[bi][j] = 0;
            else if(a[i-1] == b[j-1])
                 L[bi][j] = L[1 - bi][j - 1] + 1;
            else
                L[bi][j] = max(L[1 - bi][j],
                               L[bi][j - 1]);
        }
    }
    return L[bi][m];
}

int main() {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    //input
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int j = 0; j < m; j++)
        cin >> b[j];

    cout << lcs(a, b, n, m);

    return 0;
}
