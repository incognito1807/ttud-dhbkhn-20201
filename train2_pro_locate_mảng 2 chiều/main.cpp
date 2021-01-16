#include <bits/stdc++.h>
#include <algorithm>
#include <utility>
#include <cstring>
#include <vector>

using namespace std;

const int N = 2010;
vector<pair<int, int>> a, b;
int c[N][N];
int l, w;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int Max = 0;
        cin >> l >> w;
        int x;
        for(int i = 0; i < l; i++)
            for(int j = 0; j < w; j++) {
                cin >> x;
                if (x == 1)
                    a.push_back(make_pair(i, j));
            }
        for(int i = 0; i < l; i++)
            for(int j = 0; j < w; j++) {
                cin >> x;
                if (x == 1)
                    b.push_back(make_pair(i, j));
            }
        for(int i = 0; i < a.size(); i++) {
            for(int j = 0; j < b.size(); j++) {
                int u = a[i].first - b[j].first;
                int v = a[i].second - b[j].second;
                Max = max(Max, ++c[u + N/2][v + N/2]);
            }
        }
        cout << Max << endl;
        a.clear();
        b.clear();
        memset(c, 0, sizeof(c));
    }
    return 0;
}
