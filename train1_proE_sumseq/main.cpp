#include <bits/stdc++.h>

using namespace std;

int addMod(int a, int b, int p) {
    a = a % p;
    b = b % p;
    int tmp = p - a;
    if (tmp < b)
        return b - tmp;
    return a + b;
}

int main()
{
    int n, ans = 0, p = 1000000007;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ans = addMod(ans, a, p);
    }
    cout << ans;
    return 0;
}
