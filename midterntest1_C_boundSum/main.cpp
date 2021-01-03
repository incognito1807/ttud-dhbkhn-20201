#include <bits/stdc++.h>
using namespace std;

map <int, int> hm;
map <int, int>:: iterator it;
int z = 0;

int soe(int a[], int i, int j) {
    int sum=0;
    for(int index=i; index<i+j; index++)
        sum+=a[index];
    return sum;
}

void cnt(int a[], int n, int k, int h) {
    for(int j=1; j<=n; j++)
        for(int i=0; i<n-j+1; i++)
            hm[soe(a, i, j)]++;
    for(it = hm.begin(); it != hm.end(); it++)
        if(it->first >= k && it->first <= h)
            z += it->second;
}

main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, h;
    cin >> n >> k >> h;
    int a[n];
    for(int i=0; i<n; i++)
        cin >> a[i];
    cnt(a, n, k, h);
    cout << z;
    return 0;
}
