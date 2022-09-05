#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    int ans = 1;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        ans = (ans * (t + 1)) % mod;
    }
    cout << (ans - 1 + mod) % mod << endl;
}

signed main()
{
    #ifdef DEBUG
    freopen("J.in","r",stdin);
    #endif
    cin.tie(nullptr)->sync_with_stdio(false);    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}