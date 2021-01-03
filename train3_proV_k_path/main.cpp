#include <bits/stdc++.h>
using namespace std;
int n, k, m, cnt = 0, u, v, tmp[31], A[31][31];
bool visited[31];

void input() {
	cin >> n >> k >> m;
	tmp[0] = n;
	for(int i = 1; i <= n; i++)
		A[0][i] = i;
	for(int i = 0; i < m; i++) {
		cin >> u >> v;
		A[u][++tmp[u]] = v;
		A[v][++tmp[v]] = u;
	}
}

void Try(int x) {
	for(int i = 1; i <= tmp[x]; i++) {
		int next = A[x][i];
		if(!visited[next]) {
		    visited[next] = true;
			if(k--)
				Try(next);
			else
				cnt++;
			k++;
			visited[next] = false;
		}
	}
}
int main() {
	input();
	Try(0);
	cout << cnt/2;
	return 0;
}
