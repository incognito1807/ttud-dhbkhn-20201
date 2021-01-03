#include<bits/stdc++.h>
using namespace std;

int n;
int h,w;
int dp[610][610];
int ht[250],wt[250];

void input() {
    cin >> w >> h;
    cin >> n;
    for(int j = 0; j < n; j++)
        cin >> wt[j] >> ht[j];
    for(int i = 0; i <= w; i++)
        for(int j = 0; j <= h; j++)
            dp[i][j] = -1;
}

int calc(int x, int y) {
    int m = 1e9, temp;
    if(dp[x][y] != -1)
        return(dp[x][y]);
    int flag = 0;
    for(int i = 0;i < n; i++)
        if(wt[i] <= x && ht[i] <= y) {
                flag = 1;
                temp = min( calc(x,y-ht[i])+calc(x-wt[i],ht[i]) , calc(x-wt[i],y)+calc(wt[i],y-ht[i]) );
                if(temp < m)
                    m = temp;
        }
    if(flag == 0) {
        dp[x][y] = x*y;
        return dp[x][y];
    } else {
        dp[x][y] = m;
        return dp[x][y];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    cout << calc(w,h);
}
