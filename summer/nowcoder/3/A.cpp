//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 1e5+5;
LL n, k, x[maxn], a[maxn], b[maxn];
unordered_map<LL, bool> mp;

struct Edge {
    LL to, next;
}e[maxn<<2];

LL tot, head[maxn<<1], fa[maxn<<1][25], deep[maxn<<1];
bool vis[maxn<<1];
LL p[2][2], q[2]; // 0min A, 1max B
set<LL> s;

void add(LL x, LL y) {
    tot++;
    e[tot].next = head[x];
    e[tot].to = y;
    head[x] = tot;
}

void dfs(LL u, LL f) {
    LL idx = (u<=n)?0:1;
    if(p[idx][0]==-1&&mp[u]) p[idx][0] = u;
    if(mp[u]) p[idx][1] = u;
    deep[u] = deep[f]+1;
    fa[u][0] = f;
    for(int i=head[u]; i; i=e[i].next) {
        LL v=e[i].to;
        if(vis[v]) continue;
        vis[v] = 1;
        dfs(v, u);
    }
}

LL lca(LL x, LL y) {
    if(deep[x]<deep[y]) swap(x,y);
    for(int i=20; i>=0; i--) {
        if(deep[fa[x][i]]>=deep[y]) {
            x = fa[x][i];
        }
        if(x==y) return x;
    }
    for(int i=20; i>=0; i--) {
        if(fa[x][i]!=fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}

void lca_init() {
	Ms(vis, 0);
	Ms(deep, 0);
    vis[1] = vis[n+1] = 1;
    deep[1] = deep[n+1] = 0;
    Fo(i,0,1) Fo(j,0,1) p[i][j] = -1;
    dfs(1, 0);
    dfs(n+1, 0);
    for(int i=1; i<=20; i++) {
        for(int j=1; j<=n; j++) {
            fa[j][i] = fa[fa[j][i-1]][i-1];
        }
        for(int j=n+1; j<=2*n; j++) {
            fa[j][i] = fa[fa[j][i-1]][i-1];        	
		}
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>k;
    Fo(i,1,k) {
        cin>>x[i];
        mp[x[i]] = mp[x[i]+n] = 1;
    }
    Fo(i,1,n) cin>>a[i];
    Fo(i,1,n-1) {
        LL x; cin>>x;
        add(i+1, x);
        add(x, i+1);
    }
    Fo(i,1,n) cin>>b[i];
    Fo(i,1,n-1) {
        LL x; cin>>x;
        add(i+1+n, x+n);
        add(x+n, i+1+n);
    }
    lca_init();
    Fo(i,0,1) q[i] = lca(p[i][0], p[i][1]);
    s.insert(p[0][0]); s.insert(p[0][1]);
    s.insert(p[1][0]-n); s.insert(p[1][1]-n);
    LL ans = 0;
    if(a[q[0]]>b[q[1]-n]) ans+=k-s.size();
    for(auto it:s) {
        // cout<<it<<endl;
        mp[it] = mp[it+n] = 0;
        lca_init();
        Fo(i,0,1) q[i] = lca(p[i][0], p[i][1]);
        if(a[q[0]]>b[q[1]-n])  ans++;     
        // Fo(i,0,1) cout<<q[i]<<' ';
        // cout<<endl;    
        // Fo(i,0,1) Fo(j,0,1) cout<<p[i][j]<<' ';
        // cout<<endl;
        mp[it] = mp[it+n] = 1;
    }
    cout<<ans;
    return 0;
}