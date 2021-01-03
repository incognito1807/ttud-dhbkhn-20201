#include <bits/stdc++.h>
using namespace std;

void solve(unsigned long long a, unsigned long long b) {
    unsigned long long c, a1, b1;
    int c1, c0, a0, b0;
    a1 = a/10;
    b1 = b/10;
    a0 = a%10;
    b0 = b%10;
    c1 = (a0+b0)/10;
    c0 = (a0+b0)%10;
    c = a1+b1+c1;
    if (c>0) {
        cout << c << c0 << endl;
        }
    else
        cout << c0 << endl;
}

int main() {
    unsigned long long a, b;
    cin >> a >> b;
    solve(a, b);
    return 0;
}
