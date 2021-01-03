#include<bits/stdc++.h>
using namespace std;
int s[7] = {4,8,15,16,23,42};
int i[7];
int ar[4];
int res[7];

bool check() {
    int cnt = 0;
    for(int z = 1; z <= 5; z++) {
        for(int q = z + 1; q <= 6; q++) {
            if(i[z] == i[q])
                cnt++;
        }
    }
    if(cnt == 0)
        return true;
    else
        return false;
}

int flag = 0;
void solve(int ar[]) {
    if(flag == 0) {
        for(i[1] = 0; i[1] < 6; i[1]++) {
            if(flag != 0)
                break;
            for(i[2] = 0; i[2] < 6; i[2]++) {
                if(flag != 0)
                    break;
                for(i[3] = 0; i[3] < 6; i[3]++) {
                    if(flag != 0)
                        break;
                    for(i[4] = 0; i[4] < 6; i[4]++) {
                        if(flag != 0)
                            break;
                        for(i[5] = 0; i[5] < 6; i[5]++) {
                            if(flag != 0)
                                break;
                            for(i[6] = 0; i[6] < 6; i[6]++) {
                                if(flag != 0)
                                    break;
                                else if(s[i[1]] * s[i[2]] == ar[1] && s[i[2]] * s[i[3]] == ar[2] && s[i[3]] * s[i[4]] == ar[3] && s[i[4]] * s[i[5]] == ar[4]) {
                                    if(check()) {
                                        res[0] = s[i[1]];
                                        res[1] = s[i[2]];
                                        res[2] = s[i[3]];
                                        res[3] = s[i[4]];
                                        res[4] = s[i[5]];
                                        res[5] = s[i[6]];
                                        flag++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int main() {
    cout << "? 1 2" << endl;
    fflush(stdout);
    cin >> ar[1];

    cout << "? 2 3" << endl;
    fflush(stdout);
    cin >> ar[2];

    cout << "? 3 4" << endl;
    fflush(stdout);
    cin >> ar[3];

    cout << "? 4 5" << endl;
    fflush(stdout);
    cin >> ar[4];
    solve(ar);
    printf("! %d %d %d %d %d %d\n", res[0], res[1], res[2], res[3], res[4], res[5]);
    return 0;
}
