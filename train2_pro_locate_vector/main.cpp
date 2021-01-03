#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cstring>
using namespace std;

const int N = 1005;
int row, col;
vector<pair<int, int> > a, b;
int d[2*N][2*N];

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int Max = 0;
        cin >> row >> col;
        int x;
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++){
                cin >> x;
                if(x == 1)
                    a.push_back(make_pair(i, j));
            }
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++){
                cin >> x;
                if(x == 1)
                    b.push_back(make_pair(i, j));
            }
        for(int i = 0; i < a.size(); i++)
            for(int j = 0; j < b.size(); j++){
                int u = a[i].first - b[j].first;
                int v = a[i].second - b[j].second;
                Max = max(Max, ++d[u + N][v + N]);
            }
        cout << Max << endl;
        a.clear(), b.clear();
        memset(d, 0, sizeof(d));
    }
    return 0;
}
