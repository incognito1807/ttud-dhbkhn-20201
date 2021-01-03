#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, i;
    cin >> n;
    for (i=0; i<n; i++) {
        char kitu[1000];
        cin >> kitu;
        int a;
        a = strlen(kitu);
        if (a >10) {
            int long_mid = a - 2;
            cout << kitu[0] << long_mid << kitu[a-1] << endl;
        }
        else
            cout << kitu << endl;
    }
    return 0;
}
