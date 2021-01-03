#include <bits/stdc++.h>
using namespace std;

const int z = 10005;
int n, f;
int x[z];
const long double pi = 3.14159265358979323846264338327950;

void input() {
    cin >> n >> f;
    f++;
    for(int i = 0; i < n; i++)
        cin >> x[i];
}

bool test(long double num,long double a[]) {
    int fr = 0;
    if(num == 0)
        return false;
    for(int i = 0; i < n; i++)
        fr += (int)(a[i] / num);
    if(fr >= f)
        return true;
    else
        return false;
}

long double bs(long double a[]) {
    long double ini = 0, l = a[n-1];
    while(l - ini >= 1e-6) {
        long double m = (ini+l)/2;
        if(test(m, a))
            ini = m;
        else
            l = m;
    }
    return ini;
}
int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        input();
        long double s[z];
        sort(x, x+n);
        for (int i = 0; i < n; i++)
            s[i] = x[i] * x[i] * pi;
        long double k = bs(s);
        printf("%.6Lf\n", k);
    }
    return 0;
}
