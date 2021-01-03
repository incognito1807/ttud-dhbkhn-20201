#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;

int n, c;

bool Try(int k, int arr[]){
    int cows = 1, pos = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i]-pos >= k) {
            pos = arr[i];
            cows++;
            if (cows == c)
                return true;
        }
    }
    return false;
}

int bs(int arr[]) {
    int ini = 0, l = arr[n-1], Max = -1;
    while(l>ini) {
        int m = (ini + l) / 2;
        if(Try(m,arr)) {
            if(m > Max)
                Max = m;
            ini = m + 1;
        }
        else
            l = m;
    }
    return Max;
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n >> c;
        int x[n];
        for(int i=0; i<n; i++)
            cin >> x[i];
        sort(x,x+n);
        int k = bs(x);
        cout << k << endl;
    }
    return 0;
}
