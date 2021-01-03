#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    while(n--) {
        long long m, k, i;
        long long cnt = 0;    // đếm số người đã chia sách
        long long ans;        // tổng max
        cin >> m >> k;

        // cấu trúc dữ liệu
        vector<long long> v;

        // đầu vào
        long long a;
        for(int i = 0; i < m; i++) {
            cin >> a;
            v.push_back(a);
        }

        // set up chặn trái phải
        long long r = 5e9;
        long long l = v[m-1];
        while(l < r) {
            long long c = 0;
            long long cnt = 0;
            long long mid = (l+r)/2;
            for(i = 0; i < m; i++) {
                if(c + v[i] <= mid) {
                    c += v[i];
                } else {
                    c = v[i];
                    cnt++;
                }
            }
            if(cnt < k) {
                ans = mid;
                r = mid;
            } else
                l = mid + 1;
        }
        cnt = k - 1;
        long long sum = 0;

        // truy vết sách đã chia
        map<long long, long long> mp;
        for(i = m - 1; i >= 0; i--) {
            if(sum + v[i] > ans || cnt > i) {
                mp[i] = 1;   // xác định vị trí ngắt
                sum = v[i];
                cnt--;
            } else
                sum += v[i];
        }

        // đầu ra
        for(i = 0; i < m; i++) {
            cout << v[i] << " ";
            if(mp[i])
                cout << "/ ";
        }
        cout << endl;
    }
    return 0;
}
