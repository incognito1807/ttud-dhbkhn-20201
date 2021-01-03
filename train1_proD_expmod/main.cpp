#include <bits/stdc++.h>

using namespace std;

unsigned long long powMod( unsigned long long a, unsigned long long b, unsigned long long mod ) {
    unsigned long long res = 1;
    for ( unsigned long long i=b; i; i>>=1 ) {
        if ( i & 1 )
        res = ((res % mod) * (a % mod)) % mod;
        a = ((a % mod) * (a % mod)) % mod;
    }
    return res;
}

int main() {

    unsigned long long a, b, mod;
    cin >> a >> b;
    mod = 1000000007;
    unsigned long long result = powMod(a, b, mod);
    cout << result << endl;

    return 0;
}
