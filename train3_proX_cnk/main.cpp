#include <bits/stdc++.h>
using namespace std;

const int m = 1000000007;
int k, n;

//nhap
void input() {
    cin >> k >> n;
}

//tinh toan
unsigned long long solve(int k, int n) {
    int a[1000][1000];
    if(k==0||k==n) return 1;
    else {
        for(int i=0;i<=k;i++)
            for(int j=i;j<=n;j++)
                if(i==0||i==j)
                    a[i][j]=1;
                else
                    a[i][j]=(a[i][j-1]%m + a[i-1][j-1]%m)%m;
    }
    cout << a[k][n] << endl;
}
int main(){
    input();
    solve(k, n);
    return 0;
}
