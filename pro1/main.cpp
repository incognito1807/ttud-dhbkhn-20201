#include <bits/stdc++.h>
using namespace std;

int n;
int h, u, s, t, o, i, c;
int Z;
int cnt = 0;

bool check(int Z) {
    for(h = 0; h < 10; h++) {
        for(u = 0; u < 10; u++) {
            for(s = 0; s < 10; s++) {
                for(t = 0; t < 10; t++) {
                    for(o = 0; o < 10; o++) {
                        for(i = 0; i < 10; i++) {
                            for(c = 0; c < 10; c++) {
                                if()
                            }
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> Z;
        if(check(Z))
            cnt++;
    }
    cout << cnt;
    return 0;
}
