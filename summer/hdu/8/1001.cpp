#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 1e5 + 5;
int a[maxn];

void solve()
{
    string s;
    cin >> s;
    int odd = 0, even = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            if (i % 2 == 1) {
                odd++;
            } else {
                even++;
            }
        }
    }
    for (int i = s.size() - 1; i >= 0; i--) {
        if (i % 2 == 1) {
            if (odd) {
                a[i] = 1;
                odd--;
            } else {
                a[i] = 0;
            }
        } else {
            if (even) {
                a[i] = 1;
                even--;
            } else {
                a[i] = 0;
            }
        }
    }
    for (int i = 0; i < s.size(); i++) {
        cout << a[i];
    }
    cout << endl;
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}