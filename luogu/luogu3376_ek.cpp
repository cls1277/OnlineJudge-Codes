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
LL dis[maxn], pre[maxn];

bool bfs() {
    Ms(vis, 0);
    queue<LL> q;
    q.push(s);
    vis[s] = 1;
    dis[s] = INT_MAX;
    while(!q.empty()) {
        LL u = q.front(); q.pop();
        if(u==t) return 1;
        Eo(i,u,e) {
            LL v = e[i].to;
            if(vis[v]||e[i].val<=0) continue;
            dis[v] = min(dis[u], e[i].val);
            vis[v] = 1;
            pre[v] = i; // 存的i
            q.push(v);
        }
    }
    return 0;
}

LL ans;

void update() {
    LL x = t;
    while(x!=s) {
        LL i = pre[x];
        e[i].val  -= dis[t];
        e[i^1].val += dis[t];
        x = e[i^1].to;
    }
    ans += dis[t];
}

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
    while(bfs()) update();
    cout<<ans;
    return 0;
}