#include <bits/stdc++.h>
using namespace std;

const int Max = 100;
int n, m;
float c[Max][Max], r[Max][Max], l[Max][Max];
int u, v;
int cnt;
int check;

void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            c[i][j] = 0;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        c[u-1][v-1] = -1;
        c[v-1][u-1] = -1;
        c[u-1][u-1] += 1;
        c[v-1][v-1] += 1;
    }
    cnt = n;
}

bool isInterconnection(float c[Max][Max], int z) {
    int x = 0;
    for(int i = 0; i < z; i++)
        if(c[i][i] > 1)
            x++;
    if(x != 0)
        return true;
    else
        return false;
}

void setArray(float c[Max][Max], int z) {
    for(int i = n-1; i >= 0; i--) {
        check = 0;
        for(int j = 0; j < z; j++) {
            if(c[i][j] == 0)
                check++;
        }
        if(check == z) {
            cnt--;
            if(i != n-1) {
                for(int k = i; k < n-1; k++) {
                    for(int j = 0; j < n; j++) {
                        c[k][j] = c[k+1][j];
                    }
                }
                for(int k = i; k < n-1; k++) {
                    for(int j = 0; j < n; j++) {
                        c[j][k] = c[j][k+1];
                    }
                }
            }
        }
    }
}

void process(float c[Max][Max], int z) {
    for(int k = 0; k < z; k++) {
        r[k][k] = c[k][k];
        l[k][k] = 1;
        for(int i = k+1; i < z; i++) {
            l[i][k] = c[i][k]/r[k][k];
            r[k][i] = c[k][i];
            r[i][k] = 0;
            l[k][i] = 0;
        }
        for(int i = k+1; i < z;i++)
            for(int j = k+1; j < z; j++)
                c[i][j] = c[i][j] - l[i][k]*r[k][j];
    }
}

float det(float c[Max][Max], int z) {
    float tmp = 1;
    for(int i = 0; i < z; i++)
        tmp *= c[i][i];
    return tmp;
}

int main() {
    input();
    if(!isInterconnection(c, n))
        cout << 0;
    else {
        setArray(c, n);
        process(c, cnt-1);
        cout << det(c, cnt-1) << endl;
    }
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++)
    //         cout << c[i][j] << " ";
    //     cout << endl;
    // }
    return 0;
}
