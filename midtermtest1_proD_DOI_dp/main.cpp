#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int a[n+1];
    int L1[n+1]; // Tăng từ trái
    int L2[n+1]; // Giảm từ trái
    int R1[n+1]; // Tăng từ phải
    int R2[n+1]; // Giảm từ phải
    memset(L1, 0, sizeof(L1));
    memset(L2, 0, sizeof(L2));
    memset(R1, 0, sizeof(R1));
    memset(R2, 0, sizeof(R2));
    L1[1] = 1;
    L2[1] = 1;
    R1[n] = n;
    R2[n] = n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<n; i++){
        if(a[i]>a[i+1]) L1[i+1] = L1[i];
        else L1[i+1] = i+1;
        if(a[i]<a[i+1]) L2[i+1] = L2[i];
        else L2[i+1] = i+1;
    }
    for(int i=n-1; i>=1; i--){
        if(a[i]<a[i+1]) R1[i] = R1[i+1];
        else R1[i] = i;
        if(a[i]>a[i+1]) R2[i] = R2[i+1];
        else R2[i] = i;
    }
    int dinh=0;
    int day=0;
    for(int i=1; i<=n; i++){
        dinh = max(dinh, min(i-L2[i], R2[i]-i));
        day = max(day, min(i-L1[i], R1[i]-i));
    }
    cout << dinh << " " << day << endl;
    return 0;
}
