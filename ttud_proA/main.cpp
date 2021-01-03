#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5+2;
int n;
int a[MAX];
int tmp;
int cnt = 1;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    tmp = a[0];
    for(int i = 1; i < n; i++) {
        if(a[i] <= tmp) {
            cnt ++;
        }
        tmp = a[i];
    }
    cout << cnt;
    return 0;
}
