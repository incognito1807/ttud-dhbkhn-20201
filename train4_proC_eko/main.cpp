#include <bits/stdc++.h>
using namespace std;

const int z = 1000006;
int n, k;
int a[z];
int Max = -1;
long long int h = 0;

void input() {
	cin >> n >> k;
	for(int i = 0 ; i < n ; i++) {
		cin >> a[i];
		if(a[i] > Max)
			Max = a[i];
	}
}

void solve() {
    long long int low = 0;
	long long int high = Max;
	long long int cnt, mid;

	while(low <= high) {
		mid = (high + low) /2 ;
		cnt = 0;
		for(int i = 0 ; i < n ; i++) {
			long long int tmp = a[i] - mid;
			if(tmp > 0)
			    cnt += tmp;
		}

		if(cnt == k) {
			h = mid;
			break;
		} else if(cnt < k) {
			high = mid - 1;
		} else {
			low = mid + 1;
			if(mid > h)
				h = mid;
		}
	}
}

int main () {
    ios::sync_with_stdio(false);
	input();
	solve();
    cout << h;
	return 0;
}
