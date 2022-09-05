#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 505;

char mp[maxn][maxn];
int dp[maxn][maxn]; // 1: Alice 2: Tie, 3: Bob;

int n, m;
// Alice 一定赢的dfs
int dfs(bool aturn, int x, int y)
{
    if (dp[x][y])
        return dp[x][y];
    else if (mp[x][y] == 'A')
        return 1;
    else if (mp[x][y] == 'B')
        return 3;
    else if (x == n && y == m)
        return 2;
    if (x + 1 <= n) {
        if (!dp[x + 1][y]) {
            dp[x + 1][y] = dfs(!aturn, x + 1, y);
        }
    }
    if (y + 1 <= m) {
        if (!dp[x][y + 1]) {
            dp[x][y + 1] = dfs(!aturn, x, y + 1);
        }
    }
    if (aturn) { // 现在是Alice走
        int res = 3;
        if (x + 1 <= n)
            res = min(res, dp[x + 1][y]);
        if (y + 1 <= m)
            res = min(res, dp[x][y + 1]);
        return res;
    } else { // 现在是Bob走
        int res = 1;
        if (x + 1 <= n)
            res = max(res, dp[x + 1][y]);
        if (y + 1 <= m)
            res = max(res, dp[x][y + 1]);
        return res;
    }
    return 2; // 不可能到这吧
}

// Alice 一定输的dfs
int dfs2(bool aturn, int x, int y)
{
    if (dp[x][y])
        return dp[x][y];
    else if (mp[x][y] == 'A')
        return 1;
    else if (mp[x][y] == 'B')
        return 3;
    else if (x == n && y == m)
        return 2;
    if (x + 1 <= n) {
        if (!dp[x + 1][y]) {
            dp[x + 1][y] = dfs2(!aturn, x + 1, y);
        }
    }
    if (y + 1 <= m) {
        if (!dp[x][y + 1]) {
            dp[x][y + 1] = dfs2(!aturn, x, y + 1);
        }
    }
    if (aturn) { // 现在是Alice走
        int res = 1;
        if (x + 1 <= n)
            res = max(res, dp[x + 1][y]);
        if (y + 1 <= m)
            res = max(res, dp[x][y + 1]);
        return res;
    } else { // 现在是Bob走
        int res = 3;
        if (x + 1 <= n)
            res = min(res, dp[x + 1][y]);
        if (y + 1 <= m)
            res = min(res, dp[x][y + 1]);
        return res;
    }
    return 2; // 不可能到这吧
}

// Alice 一定平的dfs
int dfs3(bool aturn, int x, int y)
{
    if (dp[x][y])
        return dp[x][y];
    else if (mp[x][y] == 'A')
        return 1;
    else if (mp[x][y] == 'B')
        return 3;
    else if (x == n && y == m)
        return 2;
    if (x + 1 <= n) {
        if (!dp[x + 1][y]) {
            dp[x + 1][y] = dfs3(!aturn, x + 1, y);
        }
    }
    if (y + 1 <= m) {
        if (!dp[x][y + 1]) {
            dp[x][y + 1] = dfs3(!aturn, x, y + 1);
        }
    }
    if (aturn) { // 现在是Alice走
        bool res = false; // 是否平局
        if (x + 1 <= n)
            res |= dp[x + 1][y] == 2;
        if (y + 1 <= m)
            res |= dp[x][y + 1] == 2;
        return res ? 2 : 1;
    } else { // 现在是Bob走
        bool res = false; // 是否非平局
        if (x + 1 <= n)
            res |= dp[x + 1][y] != 2;
        if (y + 1 <= m)
            res |= dp[x][y + 1] != 2;
        return res ? 1 : 2;
    }
    return 2; // 不可能到这吧
}

void solve()
{
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", mp[i] + 1);
    }
    memset(dp, 0, sizeof dp);
    printf("%s ", dfs(true, 1, 1) == 1 ? "yes" : "no");
    memset(dp, 0, sizeof dp);
    printf("%s ", dfs3(true, 1, 1) == 2 ? "yes" : "no");
    memset(dp, 0, sizeof dp);
    printf("%s\n", dfs2(true, 1, 1) == 3 ? "yes" : "no");
    // printf("\n");
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         printf("%lld ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
}

signed main()
{
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    // cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    scanf("%lld", &T);
    while (T--) {
        solve();
    }
    return 0;
}