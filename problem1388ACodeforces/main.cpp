#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
#define Inf 0x3f3f3f3f
#define Maxn 20


int main() {
    int t, a, b, c, d;
    long int n;
    cin >> t;
    while (t--) {
        cin >> n;
        a = 6;
        b = 10;
        c = 14;
        d = a + b + c;
        d = n - d;
        if (d == a || d == b || d == c) {
            c = 15; d -= 1;
            cout << "YES" << endl;
            cout << a << b << c << d;
        }
        else if (d > 0) {
            cout << "YES" << endl;
            cout << a << b << c << d;
        }
        else
            cout << "NO" << endl;
    }
    return 0;

}
