#include <bits/stdc++.h>
using namespace std;
int s;

bool foundsus(vector<int>* interact, int n, int* visited){
    deque<int> q;
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            visited[i] = 1;
            q.push_back(i);
            while(!q.empty()) {
                int top = q.front();
                q.pop_front();
                for(int k = 0; k < interact[top].size(); k++) {
                    int j = interact[top][k];
                    if(!visited[j]) {
                        visited[j] = -visited[top];
                        q.push_back(j);
                    } else {
                        if(visited[j] == visited[top]) {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    for(int k = 1; k <= s; k++) {
        int n, m;
        cin >> n >> m;
        vector<int> interact[n];

        for(int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            interact[x - 1].push_back(y - 1);
            interact[y - 1].push_back(x - 1);
        }
        int visited[n];
        for(int i = 0; i < n; i++) {
            visited[i] = 0;
        }

        cout << "Scenario #" << k << ":" << endl;
        if(foundsus(interact, n, visited))
            cout << "Suspicious bugs found!" << endl;
        else
            cout << "No suspicious bugs found!" << endl;
    }
    return 0;
}
