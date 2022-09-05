#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e6 + 6;

void solve()
{
    unordered_map<int, int> ss;
    int n, m, p, x, a, b, c;
    cin >> n >> m >> p >> x >> a >> b >> c;

    // if (a == 0 && b == 0 || x == 0) {
    //     cout << min(n, m) << endl;
    //     return;
    // }

    for (int i = 0; i < n; i++) {
        x = (a * x * x + b * x + c) % p;
        if (ss.find(x) == ss.end())
            ss.emplace(x, i);
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        x = (a * x * x + b * x + c) % p;
        if (ss.find(x) != ss.end()) {
            ans = max(ans, min(n - ss[x], m - i));
        }
    }
    cout << ans << endl;
    return;
}

signed main()
{
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}