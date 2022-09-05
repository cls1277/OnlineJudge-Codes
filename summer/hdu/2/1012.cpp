#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll maxn = 1024;
ll dp[maxn];

void init_dp() {
    std::fill(dp, dp+maxn, INT32_MAX);
    dp[0] = 0;
    for (ll n = 1; n < maxn; n++) {
        if (n >= 31) {
            dp[n] = min(dp[n], dp[n-31]+1);
        }
        if (n >= 7) {
            dp[n] = min(dp[n], dp[n-7]+1);
        }
    }
    for (ll i = 1; i < maxn; i++) {
        if(dp[i] == INT32_MAX) {
            dp[i] = -1;
        }
    }
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);    
	init_dp();
    int T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        if (n < 365) {
            cout << dp[n] << endl;
        } else if (dp[n%365] != -1) {
            cout << dp[n%365] + n/365 << endl;
        } else {
            cout << dp[n%365+365] + n/365 - 1 << endl;
        }
    }
    return 0;
}