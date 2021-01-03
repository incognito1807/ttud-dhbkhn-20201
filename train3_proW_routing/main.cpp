#include <bits/stdc++.h>
using namespace std;

const int Max = 105;
int n, R, u, dist;
string s;
int a[Max][Max];
int m[Max];
bool c[Max];
vector<vector<int> > r;
stack<int> tr;

void input() {
	int temp;
	cin >> n >> R;
	for(int i = 1; i <= n; i++)
		c[i] = true;
	for(int i = 1; i <= R; i++)
		m[i] = 1e9;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++)
			cin >> a[i][j];
	}
	for(int i = 0; i <= R; i++)
		r.push_back(vector<int>());
	getline(cin, s);
	for(int i = 1; i <= R; i++) {
		getline(cin, s);
		istringstream is(s);
		while(is >> temp)
			r[i].push_back(temp);
	}
}

void solve(unsigned x) {
	if(!x) {
		if(r[u].size() == 2) {
		    int tmp = a[r[u][0]][r[u][1]];
		    if(tmp != 0)
		        m[u] = tmp;
		}
		else {
			dist = 0;
			tr.push(r[u][0]);
			solve(r[u][0]);
			tr.pop();
		}
	} else
		for(unsigned i = 1; i < r[u].size() - 1; i++) {
			unsigned nt = r[u][i];
			if(x != nt && a[x][nt] != 0 && c[nt] && m[u] > dist + a[x][nt]) {
				c[nt] = false;
				dist += a[x][nt];
				tr.push(nt);
				if(tr.size() < r[u].size() - 1) {
					solve(nt);
					c[nt] = true;
					dist -= a[x][nt];
					tr.pop();
				} else {
					if(a[nt][r[u].back()] != 0) {
					    int tmp = dist + a[nt][r[u].back()];
					    if(tmp < m[u])
					        m[u] = tmp;
					}
					c[nt] = true;
					dist -= a[x][nt];
					tr.pop();
				}
			}
		}
}

int main() {
	input();
	for(u = 1; u <= R; u++) {
		solve(0);
		if(m[u] != 1e9)
			cout << m[u] << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}
