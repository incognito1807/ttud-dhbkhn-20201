#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main(){
    int n;
    double l;
    int a[n];
    double maxi = 0;
    cin >> n >> l;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    double dau = a[0];
    double cuoi = l - a[n-1];
    for(int i = 1; i < n-1; i++){
        if(a[i+1]-a[i] > maxi)
            maxi = a[i+1] - a[i];
    }
    maxi = maxi / 2;
    if(dau > maxi)
        maxi = dau;
    if(cuoi > maxi)
        maxi = cuoi;
    cout << std::setprecision(10);
    double z{maxi};
    cout << z;
    return 0;
}
