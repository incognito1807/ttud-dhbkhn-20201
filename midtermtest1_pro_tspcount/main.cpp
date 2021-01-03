#include<bits/stdc++.h>
using namespace std;
int n, M, cost = 0;
int **A;
bool *a, *b;
int cnt = 0;
stack<int> route;

void TSP(int i) {
	for (int j = 2; j < n + 1; j++) {
		if ((i != j) && (b[j] && A[i][j] != 0)) {
			if (M < cost + A[i][j])
				continue;
			b[j] = 0;
			route.push(j);
			cost += A[i][j];
			if (route.size() < n)
				TSP(j);
			else {
				cost += A[j][1];
				if (cost <= M) {
					cnt++;
				}
				cost -= A[j][1];
			}
			b[j] = 1;
			route.pop();
			cost -= A[i][j];
		}
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cin >> n >> M;
	A = new int*[n + 1];
	for (int i = 1; i < n + 1; i++) {
		A[i] = new int[n + 1];
		for (int j = 1; j < n + 1; j++)
			cin >> A[i][j];
	}
	a = new bool[n + 1];
	b = new bool[n + 1];
	for (int i = 1; i < n + 1; i++) {
		a[i] = 1;
		b[i] = 1;
	}
	route.push(1);
	TSP(1);
	cout << cnt;
	return 0;
}
