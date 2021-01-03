#include <bits/stdc++.h>
using namespace std;

//input
const int Max = 15;
int n;
int k = 1;
int c[2*Max][2*Max];

//cau truc du lieu
int cnt = 0;    //so nguoi
int visited[Max];    //tham
int s = 0;      //quang duong
int pre[2*Max];    //luu vi tri truoc
int minimum = 1e9;
int q = 1e9;

//tao trang thai ban dau
void setup(){
    for(int i = 0; i <= n; i++)
        visited[i] = 0;
    for(int i = 0; i <= 2*n; i++)
        pre[i] = 0;
}

//dau vao
void input(){
    for(int i = 0; i <= 2*n; i++){
        for(int j = 0; j <= 2*n; j++){
            cin >> c[i][j];
            if(c[i][j] < q && i != j)
                q = c[i][j];
        }
    }
}

//kiem tra
bool check(int i, int z){
    if(visited[i] == 0)
        return true;
    return false;
}

//solution
void Try(int z, int previ){
    //check di het chua
    if(z > 2 * n){
        s += c[previ][0];
        if(s < minimum)
            minimum = s;
        s -= c[previ][0];
        return;
    }
    //duyet mang
    for(int i = 1; i <= n; i++){
        //chua tham thi vao
        if(check(i, z)){
            if(cnt + 1 <= k){
                cnt++;
                s += c[previ][i];
                visited[i] = 1;
                pre[i] = previ;
                if(s + (2 * n + 1 - z) * q < minimum)
                    Try(z+1, i);
                cnt--;
                s -= c[previ][i];
                previ = pre[i];
                visited[i] = 0;
                pre[i] = 0;
            }
        }
        else if(visited[i] == 1){
            cnt--;
            s += c[previ][i+n];
            visited[i] = -1;
            pre[i + n] = previ;
            if(s + (2 * n + 1 - z) * q < minimum)
                Try(z + 1, i + n);
            cnt++;
            s -= c[previ][i+n];
            previ = pre[i+n];
            visited[i] = 1;
            pre[i + n] = 0;
        }
    }
}

int main(){
    cin >> n;
    setup();
    input();
    Try(1, 0);
    cout << minimum;
    return 0;
}
