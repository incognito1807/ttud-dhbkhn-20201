#include <bits/stdc++.h>
using namespace std;

int n, m;
int minimum = 1e9;
const int Max = 20;
int c[Max];         //tin chi mon hoc
int a[Max][Max];    //ma tran yeu cau
int rq[Max];   //mon hoc yeu cau
int cnt[Max]; //tai trong ki do

int max_sub(int* arr){
    int max_z = 0;
    for(int i = 0; i <= m; i++){
        if(arr[i] > max_z)
            max_z = arr[i];
    }
    return max_z;
}
//khoi tao
void setup(){
    for(int i = 1; i <= m; i++){
        cnt[i] = 0;
    }
}

//nhap
void input(){
    for(int i = 0; i < n; i++) {
        cin >> c[i];
        rq[i] = 0;
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
}

//kiem tra
bool check(int k, int t){
    if(rq[k] == 0){
        for(int i = 0; i < n; i++){
            if(a[k][i] && rq[i] && rq[i] < t || a[i][k] && rq[i] && rq[i] > t)
                    return false;
        }
        return true;
    }
    return false;
}

//duyet
void Try(int k){
    if(k == n){
        int z = max_sub(cnt);
        if(minimum > z)
            minimum = z;
    }
    for(int i = 1; i < m + 1; i++){
        if(check(k, i)){
            rq[k] = i;
            cnt[i] += c[k];
            if(cnt[i] < minimum)
                Try(k+1);
            rq[k] = 0;
            cnt[i] -= c[k];
        }
    }
}

int main(){
    cin >> n >> m;
    setup();
    input();
    Try(0);
    cout << minimum;
    return 0;
}
