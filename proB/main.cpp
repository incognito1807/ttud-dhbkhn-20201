#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
deque <int> s;
deque <int> d;
string t;
int l;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        s.push_back(a[i]);
    }
    cin >> t;
    l = t.length();
    for(int i = 0; i < l; i++) {
        if(t[i] == 'C') {
            d.push_back(s.front());
            s.pop_front();
        } else {
            s.push_front(d.front());
            d.pop_front();
        }
    }
    for(int i = 0; i < n; i++) {
        cout << s.front() << " ";
        s.pop_front();
    }
    return 0;
}
