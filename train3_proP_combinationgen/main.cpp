#include <bits/stdc++.h>
using namespace std;
const int Max = 10005;

int main(){
    int n, m;
    int a[Max];
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> a[i];
    }
    int z = 0;
    for(int i = 1; i <= m; i++){
        if(a[i] == n-m+i)
            z += 1;
    }
    if(z == m)
        cout << "-1";
    else{
        int corr;
        int cnt = 0;
        for(int i = m; i >= 1; i--){
            if(cnt == 0){
                if(a[i] != n-m+i){
                    cnt += 1;
                    corr = i;
                }
            }
        }
        a[corr] = a[corr] + 1;
        for(int j = corr+1; j <= m; j++)
            a[j] = a[corr] + j - corr;
        for(int i = 1; i <= m; i++)
            cout << a[i] << " ";
    }
    return 0;
}
