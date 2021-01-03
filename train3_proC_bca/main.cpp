#include <bits/stdc++.h>
using namespace std;
int n, m;
int res = 1e9;

//tìm max mảng
int max_sub(int* arr){
    int max_z = 0;
    for(int i = 0; i < m; i++){
        if(arr[i] > max_z)
            max_z = arr[i];
    }
    return max_z;
}

//kiểm tra tính hợp lệ
bool check(int t, int i, int* subj, int* conf, int* can){
    if(can[t*m+i] && subj[t] == -1){
        for(int j = 0; j < n; j++){
            if(subj[j] == i){
                if(conf[j*n+t] || conf[t*n+j])
                    return false;
            }
        }
        return true;
    }
    return false;
}

//duyệt
void BCA(int t, int* can, int* conf, int* subj, int* cnt){
    // neu ma xep het thi tim ng nhieu vc nhat
    if(t == n){
        int mini = max_sub(cnt);
        if(mini < res){
            res = mini;
        }
    }
    for(int i = 0; i < m; i++){
        if(check(t, i, subj, conf, can)){
            subj[t] = i;
            cnt[i]++;
            if(cnt[i] < res)
                BCA(t+1, can, conf, subj, cnt);
            cnt[i]--;
            subj[t] = -1;
        }
    }
}

int main(){
    cin >> m >> n;
    int k;
    //cấu trúc dữ liệu
    int can[n*m]; //cac mon day duoc
    int conf[n*n]; //cac mon trung tkb
    int subj[n]; //cac mon da duoc giao
    int cnt[m]; //dem khoi luong cong viec

    //khởi tạo giá trị

    //day duoc = 0
    for(int i = 0; i < m*n; i++)
        can[i] = 0;
    // trung tkb = 0
    for(int i = 0; i < n*n; i++)
        conf[i] = 0;
    // chua giao mon hoc
    for(int i = 0; i < n; i++)
        subj[i] = -1;
    //khoi luong cong viec cua cac giao vien
    for(int i = 0; i < m; i++)
        cnt[i] = 0;

    //lop co the day
    for(int i = 0; i < m; i++){
        cin >> k;
        for(int j = 0; j < k; j++){
            int z;
            cin >> z;
            can[(z-1)*m+i] = 1;
        }
    }
    //lop bi trung gio hoc
    cin >> k;
    for(int z = 0; z < k; z++){
        int i, j;
        cin >> i >> j;
        conf[(i-1)*n+(j-1)] = 1;
    }

    BCA(0, can, conf, subj, cnt);
    cout << res;
    return 0;
}
