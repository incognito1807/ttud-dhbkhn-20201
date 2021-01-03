#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
    	long long min = 0;
    	long long n, a[N], b[N];
    	cin >> n;
    	for(long long i = 0; i < n; i++)
    		cin >> a[i];
    	for(long long i = 0; i < n; i++)
    		cin >> b[i];
    	sort(a, a+n); sort(b, b+n);
    	for(long long i = 0; i < n; i++)
    		min += a[i]*b[n-i-1];
    	cout << "Case #" << i+1 << ": " << min << endl;
    }
    return 0;
}
