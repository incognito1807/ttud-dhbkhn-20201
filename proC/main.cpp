#include <bits/stdc++.h>
using namespace std;

int z, n;
int a[8];
int cnt;

int check(int a[]){
    int test = 0;
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7; j++){
            if(i != j && a[i] == a[j])
                test++;
        }
    }
    return test;
}

void Try(int k, int n) {
    if(k == 7) {
        if(!check(a) && a[0] != 0 && a[2] != 0 && (a[0]*1000+a[1]*100+a[2]*10+a[3]+a[2]*10000+a[4]*1000+a[5]*100+a[6]*10+a[3] == n))
            cnt++;
    }
    else {
        for(int i = 0; i < 10; i++) {
            a[k] = i;
            Try(k+1, n);
        }
    }
}

int main(){
    cin >> z;
    for(int x = 0; x < z; x++) {
        cin >> n;
        cnt=0;
        Try(0, n);
        cout << cnt << endl;
    }
    return 0;
}
