#include <bits/stdc++.h>
using namespace std;
const int Max = 10005;

void swap(int a[], int m, int k){
    int q = (m+k)/2;
    if(q != m){
        for(int i = m; i <= q; i++){
            int temp = a[i];
            a[i] = a[k+m-i];
            a[k+m-i] = temp;
        }
    } else{
        int temp = a[m];
        a[m] = a[k];
        a[k] = temp;
    }
}

int main(){
    int n, a[Max];
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    //check xem co phai hoan vi cuoi khong (day co giam dan khong)
    int z = 1;
    for(int i = 1; i < n; i++){
        if(a[i] > a[i+1])
            z += 1;
    }
    if(z == n)
        cout << "-1";
    else{
        // tim phan tu thu m tu phai sang sao cho a[m]<a[m+1]
        int m = n;
        for(int i = n-1; i>= 1; i--){
            if(a[i] < a[i+1]){
                m = i;
                break;
            }
        }
        //tim phan tu ben phai m sao cho no nho nhat va > a[m]
        int h = n;
        int min_right = 1e9;
        for(int i = n; i > m; i--){
            if(a[i] > a[m] && a[i] < min_right){
                min_right = a[i];
                h = i;
            }
        }
        //doi cho a[m] va a[h]
        int temp;
        temp = a[m];
        a[m] = a[h];
        a[h] = temp;

        //lat mang o sau m
        if(m+1 < n)
            swap(a, m+1, n);
        for(int i = 1; i <= n; i++)
            cout << a[i] << " ";
    }
    return 0;
}
