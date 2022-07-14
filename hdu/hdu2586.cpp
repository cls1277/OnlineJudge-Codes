//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 40005;

//wt是带权值的lca
LL deep[maxn], fa[maxn][25], wt[maxn][25];
bool vis[maxn];

struct Edge {
    LL to , next , len, val;
}e[maxn<<1];

LL tot, head[maxn];
LL n, m;

void add(LL x, LL y, LL z) {
    tot++;
    e[tot].next = head[x];
    e[tot].to = y;
    e[tot].len = z;
    head[x] = tot;
}

void dfs(LL u, LL f, LL w) {
    deep[u] = deep[f]+1;
    fa[u][0] = f;
    wt[u][0] = w;
    for(int i=head[u]; i; i=e[i].next) {
        LL v=e[i].to;
        if(vis[v]) continue;
        vis[v] = 1;
        dfs(v, u, e[i].len);
    }
}

LL lca(LL x, LL y) {
    // LL ans = INT_MAX;
    LL ans = 0;
    if(deep[x]<deep[y]) swap(x,y);
    for(int i=20; i>=0; i--) {
        if(deep[fa[x][i]]>=deep[y]) {
            // ans = min(ans, wt[x][i]);
            ans += wt[x][i];
            x = fa[x][i];
        }
        if(x==y) return ans;
    }
    for(int i=20; i>=0; i--) {
        if(fa[x][i]!=fa[y][i]) {
            // ans = min(ans, wt[x][i]);
            // ans = min(ans, wt[y][i]);
            ans += wt[x][i] + wt[y][i];
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    // ans = min(ans, wt[x][0]);
    // ans = min(ans, wt[y][0]);
    ans += wt[x][0] + wt[y][0];
    return ans;
}

void lca_init() {
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            vis[i] = 1;
            dfs(i,0,INT_MAX);
        }
    }
    for(int i=1; i<=20; i++) {
        for(int j=1; j<=n; j++) {
            fa[j][i] = fa[fa[j][i-1]][i-1];
            // wt[j][i] = min(wt[j][i-1], wt[fa[j][i-1]][i-1]);
            wt[j][i] = wt[j][i-1] + wt[fa[j][i-1]][i-1];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        cin>>n>>m;
        tot = 0;
        Ms(deep, 0); Ms(head, 0); Ms(e, 0); Ms(wt, 0); Ms(fa, 0); Ms(vis, 0);
        Fo(i,2,n) {
            LL x, y, z; cin>>x>>y>>z;
            add(x, y, z);
            add(y, x, z);
        }
        lca_init();
        Fo(i,1,m) {
            LL x, y; cin>>x>>y;
            cout<<lca(x, y)<<endl;
        }
    }
    return 0;
}