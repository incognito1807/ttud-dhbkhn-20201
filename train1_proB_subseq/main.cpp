#include <iostream>
using namespace std;

int temp = 0, Max = -9999999;
void solve(int a[n], int n) {
    for(int i = 0; i < n; i++) {
        temp += a[i];
        if(Max < temp) {
            Max = temp;
        }
        if(temp < 0)
            temp = 0;
    }
    cout << Max;
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int k=0; k<n; k++){
		cin >> a[k];
	}
    solve(a[n], n);
    return 0;
}
