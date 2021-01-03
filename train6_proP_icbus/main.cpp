#include <bits/stdc++.h>
using namespace std;

int n, k;
int MAX = 100000000;

struct Node {
    int p, c;

    Node(int p, int c){
        this->p = p;
        this->c = c;
    }
};

class com{
public:
    bool operator()(const Node& a, const Node& b) {
        if(a.c > b.c) return true;
        return false;
    }

};

typedef priority_queue<Node, vector<Node>, com> priqueue;


void dfs(int top, int cur, vector<int>* path, int* cost, int* result, priqueue& queue,  int level) {
    if(level > cost[top * 2 + 1])
        return;
    for(int i = 0; i < path[cur].size(); i++) {
        int j = path[cur][i];
        if(j != top) {
            if(result[j] > cost[top * 2] + result[top]) {
                result[j] = cost[top * 2] + result[top];
                queue.push(Node(j, result[j]));
            }
            dfs(top, j, path, cost, result, queue, level + 1);
        }
    }
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;

    int cost[2 * n];
    for(int i = 0; i < n; i++) {
        cin >> cost[i * 2] >> cost[i * 2 + 1];
    }
    vector<int> path[n];

    for(int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        path[a - 1].push_back(b - 1);
        path[b - 1].push_back(a - 1);
    }
    priqueue q;
    q.push(Node(0, 0));
    int result[n];
    for(int i = 0; i < n; i++) {
        result[i] = MAX;
    }
    result[0] = 0;
    while(!q.empty()){
        Node top = q.top();
        if(top.p == n - 1) break;
        q.pop();
        if(result[top.p] != top.c)
            continue;
        dfs(top.p, top.p, path, cost, result, q, 1);
    }
    cout << result[n - 1];
}
