//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 2e5+5;
LL n;
struct Edge {
    LL to, next, len;
};
Edge e[maxn<<1];
LL head[maxn], tot, ind[maxn], f[maxn], d[maxn];
bool vis[maxn];

void add(LL x, LL y, LL z) {
    tot++;
    e[tot].next = head[x];
    e[tot].to = y;
    e[tot].len = z;
    head[x] = tot;
}

void dp(LL u) {
    vis[u] = 1;
    d[u] = 0;
    Eo(i,u,e) {
        LL v = e[i].to;
        if(vis[v]) continue;
        dp(v);
        if(ind[v]==1) d[u] += e[i].len;
        else d[u] += min(d[v], e[i].len);
    }
}

void dfs(LL u) {
    vis[u] = 1;
    Eo(i,u,e) {
        LL v = e[i].to;
        if(vis[v]) continue;
        if(ind[u]==1) f[v] = d[v]+ e[i].len;
        else f[v] = d[v]+min(f[u]-min(d[v], e[i].len), e[i].len);
        dfs(v);
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
        Ms(vis, 0);
        Ms(head, 0);
        tot = 0;
        Ms(ind, 0);
        Ms(f, 0);
        Ms(d, 0);
        cin>>n;
        Fo(i,1,n-1) {
            LL x, y, z; cin>>x>>y>>z;
            add(x, y, z);
            add(y, x, z);
            ind[x]++; ind[y]++;
        }
        dp(1);
        f[1] = d[1];
        Ms(vis, 0);
        dfs(1);
        LL ans = 0;
        Fo(i,1,n) ans = max(ans, f[i]);
        cout<<ans<<endl;
    }
    return 0;
}