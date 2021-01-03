#include <bits/stdc++.h>
using namespace std;

const int Max = 2*1e6+5;
int n, s, f, t;
int max_s = 0, min_f = 2*1e6+5;

struct machine {
    int s, f, t;
    machine() :
        s(0), f(0), t(0) {
    }
    machine(int x, int y, int z) :
        s(x), f(y), t(z) {
    }
} m[Max];

bool check(machine m1, machine m2) {
    if(m1.t > m2.t)
        return true;
    else
        return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s >> f;
        m[i] = machine(s, f, f-s);
        max_s = max(max_s, s);
        min_f = min(min_f, f);
    }
    if(min_f >= max_s) {
        cout << -1;
        exit(0);
    } else {
        sort(m, m + n, check);
    	for(int i = 1; i < n; i++)
    		for(int j = 0; j < i; j++) {
    			if(m[j].s > m[i].f || m[i].s > m[j].f) {
    				cout << m[i].t + m[j].t;
    				exit(0);
    			}
    		}
    }
}
