#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5e5 + 5;

namespace ls {

int h[maxn];
struct Edge {
    int t, n;
} e[maxn * 2];
int tot = 0;

inline void init()
{
    for (int i = 0; i < maxn; i++) {
        h[i] = -1;
    }
    tot = 0;
}

inline void add(int u, int v)
{
    e[tot].t = v;
    e[tot].n = h[u];
    h[u] = tot++;
    e[tot].t = u;
    e[tot].n = h[v];
    h[v] = tot++;
}

int dfs(int father, int s, int& totnode)
{
    int maxval = 0;
    for (int i = h[s]; i != -1; i = e[i].n) {
        if (e[i].t == father) continue;
        int t = e[i].t;
        int tnode = 0;
        maxval = max(dfs(s, t, tnode), maxval);
        totnode += tnode;
    }
    totnode += 1;
    // printf("node=%lld, nodenum=%lld, val=%lld\n", s, totnode, maxval+totnode);
    return maxval + totnode;
}

}

void solve()
{
    int n;
    scanf("%lld", &n);
    ls::init();
    for (int i = 1; i < n; i++) {
        int s, t;
        scanf("%lld%lld", &s, &t);
        ls::add(s, t);
    }
    int tnode = 0;
    int ans = ls::dfs(-1, 1, tnode);
    printf("%lld\n", ans);
}

signed main()
{
    // cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    scanf("%lld", &T);
    while (T--) {
        solve();
    }
    return 0;
}