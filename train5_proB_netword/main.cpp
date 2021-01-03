#include <bits/stdc++.h>
using namespace std;

int tmp, t[10001], A[10001][1001], B[10001][1001];
int n, k, m, u, v, w, cost = 0, cnt = 0, p = 1000000, res = 1000000;
bool visited[10001];

void input() {
	cin >> n >> k >> m;
	t[0] = n;
	for(int i = 1; i <= n; i++)
		A[0][i] = i;
	for(int i = 0 ; i < m; i++) {
		cin >> u >> v >> w;
		if(p > w)
            p = w;
		tmp = ++t[u];
		A[u][tmp] = v;
		B[u][tmp] = w;
		tmp = ++t[v];
		A[v][tmp] = u;
		B[v][tmp] = w;
	}
}

void Try(int x) {
	for(int i = 1; i <= t[x]; i++) {
		int next = A[x][i];
		int c = B[x][i];
		if(!visited[next] && res > cost + c + (k - cnt) * p) {
			cost += c;
			visited[next] = true;
			if(cnt++ < k)
				Try(next);
			else
				res = cost;
			cnt--;
			cost -= c;
			visited[next] = false;
		}
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	input();
	Try(0);
	cout << res;
	return 0;
}
