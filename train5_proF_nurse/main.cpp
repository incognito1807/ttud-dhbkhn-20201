#include <bits/stdc++.h>
using namespace std;

const int e = 1000000007;

int n, k1, k2, s0[1001], s1[1001];
int nurse() {
	s0[0] = s0[1] = 1;
	for(int i = k1; i <= n; i++) {
		s0[i] = s1[i - 1];
		for(int j = k1; j <= max(0, min(n, k2)); j++)
			s1[i] = (s1[i] + s0[i - j]) % e;
	}
	return (s0[n] + s1[n]) % e;
}

int main() {
	cin >> n >> k1 >> k2;
	cout << nurse();
	return 0;
}
