#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = (1<<10);

bool dp[maxn][maxn]; // 背包负载，价值

void solve() {
    memset(dp, 0, sizeof dp);
    int n, m;
    cin >> n >> m;
    dp[0][0] = true;
    for (int i = 0; i < n; i++) {
        int v, w;
        cin >> v >> w;
        for (int j = v; j <= m; j++) {
            for (int k = 0; k < maxn; k++) {
                if (dp[j-v][k]) {
                    dp[j][k^w] = true;
                }
            }
        }
    }
    for (int k = maxn-1; k >= 0; k--) {
        if (dp[m][k]) {
            cout << k << endl;
            return;
        }
    }
    cout << -1 << endl;
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
