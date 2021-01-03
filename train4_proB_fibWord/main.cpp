#include<bits/stdc++.h>
using namespace std;

int pos; // tìm vị trí pattern p
unsigned long long res; // kết quả

string fibWord(int t) {
    if(t == 0)
        return "0";
    else if(t == 1)
        return "1";
    else {
        string Sn_1 = "0";
        string Sn = "1";
        string tmp;
        for(int i = 2; i <= t; i++) {
            tmp = Sn;
            Sn += Sn_1;
            Sn_1 = tmp;
        }
        return Sn;
    }
}

int find_fib(string z1) {
    for(int i = 0; i < 30; i++) {
        if(fibWord(i) == z1) {
            return i;
            break;
        }
    }
}

unsigned long long solve(int k, int pos) {
    unsigned long long a[105];
    if(pos <= 2) {
        a[1] = 1;
        a[2] = 1;
        for(int i = 3; i < 105; i++)
            a[i] = a[i-1] + a[i-2];
    } else if(pos > 2) {
        a[1] = 1;
        a[2] = 1;
        for(int i = 3; i < 105; i++) {
            if(i % 2 == 0)
                a[i] = a[i-1] + a[i-2];
            else
                a[i] = a[i-1] + a[i-2] + 1;
        }
    }
    return a[k];
}

int main() {
    int r1;
    string r2;
    int n = -1;
    string z = "2";
    for(int i = 1; i < 100; i++) {
        cin >> r1 >> r2;
        if(r1 == n && r2 == z)
            break;
        else {
            n = r1;
            z = r2;
            pos = find_fib(z);
            if(n >= pos) {
                res = solve(n - pos + 1, pos);
                cout << "Case " << i << ": " << res << endl;
            } else
                cout << "Case " << i << ": " << 0 << endl;
        }
    }
    return 0;
}
