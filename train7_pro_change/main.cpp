#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    const int Pay = 1000;
    int res = Pay - N;
    int num = 0;
    while(res >= 500) {
        res -= 500;
        num += 1;
    }
    while(res >= 100) {
        res -= 100;
        num += 1;
    }
    while(res >= 50) {
        res -= 50;
        num += 1;
    }
    while(res >= 10) {
        res -= 10;
        num += 1;
    }
    while(res >= 5) {
        res -= 5;
        num += 1;
    }
    while(res >= 1) {
        res -= 1;
        num += 1;
    }
    cout << num << endl;
    return 0;
}
