#include <bits/stdc++.h>
using namespace std;

const int Max = 1000005;
int a[Max], S[Max];
int n, l1, l2;
deque<int> d;
int res = 0;

void input() {
    cin >> n >> l1 >> l2;
    for(int i = 0; i < n; i++)
        cin >> a[i];
}

void solve() {
    for(int i = 0; i < n; i++) {
        int j = i - l1;
        while(!d.empty() && d.front() < i - l2)
            d.pop_front();
        if(j >= 0) {
            while(!d.empty() && S[d.back()] < S[j])
                d.pop_back();
            d.push_back(j);
        }
        if(d.empty())
            S[i] = a[i];
        else
            S[i] = a[i] + S[d.front()];
        res = max(res, S[i]);
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
    return 0;
}
