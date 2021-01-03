#include <bits/stdc++.h>
using namespace std;

//input
const int Max = 50;
int n, K, Q;
int d[Max];
int c[Max][Max];

//data structure
int X[Max], Y[Max];
bool visited[Max];
int seg;
int load[Max];
int cnt;
int dist;
int min_distance;

void input(){
	cin >> n >> K >> Q;
	for(int i = 1; i <= n; i++)
		cin >> d[i];
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			cin >> c[i][j];
		}
	}
}

void solution(){
    cnt++;
    for(int k = 1; k <= K; k++){
        int next = Y[k];
        while(next > 0){
            next = X[next];
            if(next == 0) break;
        }
    }
    if(min_distance > dist)
        min_distance = dist;
}

bool check_X(int v, int i, int k){
	if(v > 0 && visited[v] == true) return false;
	if(load[k] + d[v] > Q) return false;
	if(v == 0 && k == K){
        if(seg + 1 < n+K) return false;
    }
	return true;
}

bool check_Y(int v, int k){
	if(v > 0 && visited[v] == true) return false;
	if(load[k] + d[v] > Q) return false;
	return true;
}

void Try_X(int i, int k){
	for(int v = 0; v <= n; v++){
		if(check_X(v, i, k)){
			X[i] = v;
			visited[v] = true;
			load[k] += d[v];
			seg++;
			dist += c[i][v];
			if(v == 0){
				if(k == K)
					solution();
				else
					Try_X(Y[k+1], k+1);
			} else
				Try_X(v, k);
			visited[v] = false;
			load[k] -= d[v];
			seg--;
			dist -= c[i][v];
		}
	}
}

void Try_Y(int k){
	for(int v = Y[k-1]+1; v <= n; v++){
		if(check_Y(v, k)){
			Y[k] = v;
			visited[Y[k]] = true;
			seg++;
			load[k] += d[v];
			dist += c[0][v];
			if(k == K)
				Try_X(Y[1], 1);
			else
				Try_Y(k+1);
			visited[Y[k]] = false;
			load[k] -= d[v];
			seg--;
			dist -= c[0][v];
		}
	}
}

void solve(){
	for(int i = 1; i <= n; i++)
		visited[i] = false;
	seg = 0;
	Y[0] = 0;
	for(int k = 1; k <= K; k++)
		load[k] = 0;
	cnt = 0;
    dist = 0;
	min_distance = 0xffff;
	Try_Y(1);
	cout << cnt;
}

int main(){
	input();
	solve();
	return 0;
}
