//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 205;
const LL maxm = 5005;

LL tot, head[maxn], n, m, s, t, a[maxn][maxn];

struct Node {
    LL next, to, val;
}e[maxm<<1];

void add(LL x, LL y, LL z) {
    tot++;
    e[tot].next = head[x];
    e[tot].to = y;
    e[tot].val = z;
    head[x] = tot;
}

bool vis[maxn];
LL dis[maxn], pre[maxn], deep[maxn];

bool bfs() {
    Ms(vis, 0);
    queue<LL> q;
    q.push(s);
    vis[s] = 1;
    deep[s]  = 1;
    while(!q.empty()) {
        LL u = q.front(); q.pop();
        if(u==t) return 1;
        Eo(i,u,e) {
            LL v = e[i].to;
            if(vis[v]||e[i].val<=0) continue;
            vis[v] = 1;
            deep[v] = deep[u] + 1;
            q.push(v);
        }
    }
    return 0;
}

LL dfs(LL x, LL dis) {
    if(x==t) return dis;
    LL rest = dis;
    Eo(i,x,e) {
        LL v = e[i].to;
        if(!e[i].val || deep[v]!=deep[x]+1) continue;
        LL k = dfs(v, min(rest, e[i].val));
        if(!k) deep[v] = -1;
        e[i].val -= k;
        e[i^1].val += k;
        rest -= k;
    }
    return dis-rest;
}

LL ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m>>s>>t;
    tot = 1;
    Fo(i,1,m) {
        LL x, y, z; cin>>x>>y>>z;
        if(!a[x][y]) {
            add(x, y, z);
            a[x][y] = tot;
            add(y, x, 0);
        } else {
            e[a[x][y]].val += z;
        }
    }
    while(bfs()) {
        LL flow;
        while(flow = dfs(s, INT_MAX)) {
            ans += flow;
        }
    }
    cout<<ans;
    return 0;
}