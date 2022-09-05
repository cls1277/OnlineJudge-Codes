#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define int long long
const int mod = 998244353;
const int maxn = 1e5+5;

int binpow(int a, int q) {
    int res = 1;
    while (q) {
        if (q & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        q >>= 1;
    }
    return res;
}

namespace ls {

int head[maxn];
struct Edge {
    int to, nxt;
} edge[maxn*2];
int sz[maxn];
int tot = 0;


void init() {
    memset(sz, 0, sizeof sz);
    memset(head, -1, sizeof head);
    tot = 0;
}

void addEdge(int u, int v) {
    edge[tot].to = v;
    edge[tot].nxt = head[u];
    head[u] = tot++;
}

void dfs_sz(int u = 1, int fa = -1) {
    sz[u] = 1;
    for (int i = head[u]; i != -1; i = edge[i].nxt) {
        int v = edge[i].to;
        if (v == fa) continue;
        dfs_sz(v, u);
        sz[u] += sz[v];
    }
}

int ans = 0;
void dfs_ans(int u, int fa) {
    if (sz[u]%2==0) ans++;
    for (int i = head[u]; i != -1; i = edge[i].nxt) {
        int v = edge[i].to;
        if (v == fa) continue;
        dfs_ans(v, u);
    }
}

int get_ans() {
    ls::dfs_sz();
    ans = 0;
    int u = 1;
    for (int i = head[u]; i != -1; i = edge[i].nxt) {
        int v = edge[i].to;
        dfs_ans(v, u);
    }
    return ans;
}

}

void solve() {
    ls::init();
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        ls::addEdge(u, v);
        ls::addEdge(v, u);
    }
    int cnt = ls::get_ans();
    cout << (binpow(2, cnt) - 1 + mod) % mod << endl;
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