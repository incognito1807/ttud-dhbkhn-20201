#include <bits/stdc++.h>
using namespace std;

int n;                          // số loại khối đá
int N;                          // tổng số kiểu khối đá tạo ra được
int a, b, c;                    // input
int x[90], y[90], z[90];        // mảng lưu trữ kích thước khổi đá theo 3 chiều
int dp[90];                     // mảng quy hoạch động
int res;                        // chiều cao tối đa có thể tạo ra
int t = 0;                      // đếm số test

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	while(true) {
		cin >> n;
		if(n == 0)
		    break;
		t++;
		N = 3*n;
		for(int i = 0; i < n; i++) {
			cin >> a >> b >> c;
			x[3*i] = a; y[3*i] = b; z[3*i] = c;
			x[3*i+1] = b; y[3*i+1] = c; z[3*i+1] = a;
			x[3*i+2] = c; y[3*i+2] = a; z[3*i+2] = b;
		}

		for(int i = 0; i < N; i++)
    		for(int j = i+1; j < N; j++)
    			if((x[j]<x[i] && y[j]<y[i]) || (y[j]<x[i] && x[j]<y[i])){
    				swap(x[i], x[j]);
    				swap(y[i], y[j]);
    				swap(z[i], z[j]);
    			}
		res = -1;
		for(int i = 0; i < N; i++){
			dp[i] = z[i];
			for(int j = 0; j < i; j++)
				if((x[j]<x[i] && y[j]<y[i]) || (y[j]<x[i] && x[j]<y[i]))
					dp[i] = max(dp[i], dp[j]+z[i]);
			res = max(res, dp[i]);
		}
		cout << "Case " << t << ": maximum height = " << res << endl;
	}
	return 0;
}
