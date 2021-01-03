#include <bits/stdc++.h>
using namespace std;

const int n = 100005;

int main(){
    int N, t[n], Q, p[n], c[n];
    int rug = 1;
    cin >> N;
    if(N == 1){
        cin >> t[0] >> Q;
        for(int i = 0; i < Q; i++){
            cin >> p[n] >> c[n];
            cout << rug << endl;
        }
    }
    else{
        for(int i = 0; i < N; i++){
            cin >> t[i];
        }
        for(int i = 1; i < N; i++){
            if(t[i] != t[i-1])
                rug++;
        }
        cin >> Q;
        for(int i = 0; i < Q; i++){
            cin >> p[i] >> c[i];
            if(p[i] == 1){
                if(c[i] == t[p[i]-1])
                    rug = rug;
                else if(t[p[i]-1] == t[p[i]] && c[i] != t[p[i]])
                    rug += 1;
                else if(t[p[i]-1] != t[p[i]] && c[i] == t[p[i]])
                    rug -= 1;
            } else if(p[i] == N){
                if(c[i] == t[p[i]-1])
                    rug = rug;
                else if(t[p[i]-2] == t[p[i]-1] && c[i] != t[p[i]-1])
                    rug += 1;
                else if(t[p[i]-2] != t[p[i]-1] && c[i] == t[p[i]-2])
                    rug -= 1;
            } else if(p[i] < N && p[i] > 1 && N > 2){
                if(c[i] == t[p[i]-1])
                    rug = rug;
                else if(t[p[i]-2] == t[p[i]-1] && t[p[i]-1] != t[p[i]] && c[i] == t[p[i]])
                    rug = rug;
                else if(t[p[i]-2] != t[p[i]-1] && t[p[i]-1] == t[p[i]] && c[i] == t[p[i]])
                    rug = rug;
                else if(t[p[i]-2] == t[p[i]-1] && t[p[i]-1] == t[p[i]] && c[i] != t[p[i]-1])
                    rug += 2;
                else if(t[p[i]-2] != t[p[i]-1] && t[p[i]-1] != t[p[i]] && c[i] != t[p[i]-2] && c[i] == t[p[i]])
                    rug -= 1;
                else if(t[p[i]-2] != t[p[i]-1] && t[p[i]-1] != t[p[i]] && c[i] == t[p[i]-2] && c[i] != t[p[i]])
                    rug -= 1;
                else if(t[p[i]-2] == t[p[i]-1] && t[p[i]-1] != t[p[i]] && c[i] != t[p[i]-2] && c[i] != t[p[i]])
                    rug += 1;
                else if(t[p[i]-2] != t[p[i]-1] && t[p[i]-1] == t[p[i]] && c[i] != t[p[i]-2] && c[i] != t[p[i]])
                    rug += 1;
                else if(t[p[i]-2] != t[p[i]-1] && t[p[i]-2] == t[p[i]] && c[i] == t[p[i]-2])
                    rug -= 2;
            }
            t[p[i] - 1] = c[i];
            cout << rug << endl;
        }
    }
    return 0;
}
