//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 5005;
const LL maxm = 50005;

LL tot, head[maxn], n, m, s, t, a[maxn][maxn];

struct Node {
    LL next, to, len, val;
}e[maxm<<1];

void add(LL x, LL y, LL z, LL w) {
    tot++;
    e[tot].next = head[x];
    e[tot].to = y;
    e[tot].val = z;
    e[tot].len = w;
    head[x] = tot;
}

bool vis[maxn];
LL dis[maxn], pre[maxn];
LL len[maxn];

bool bfs() {
    Ms(vis, 0); Ms(dis, 0x3f); Ms(len, 0x3f);
    len[s] = 0; dis[s] = INT_MAX; vis[s] = 1;
    queue<LL>q; q.push(s);
    bool flag = 0;
    while(!q.empty()) {
        LL u = q.front(); q.pop();
        if(u==t) flag = 1;
        vis[u] = 0;
        Eo(i,u,e) {
            LL v = e[i].to;
            if(e[i].val>0&&len[v]>len[u]+e[i].len) {
                len[v] = len[u] + e[i].len;
                pre[v] = i;
                dis[v] = min(dis[u], e[i].val);
                if(!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return flag;
}

LL minn, maxx;

void update() {
    LL x = t;
    while(x!=s) {
        LL i = pre[x];
        e[i].val -= dis[t];
        e[i^1].val += dis[t];
        x = e[i^1].to;
    }
    maxx += dis[t];
    minn += dis[t]*len[t];
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
        LL x, y, z, w; cin>>x>>y>>z>>w;
        if(x==y) continue;
        add(x, y, z, w);
        add(y, x, 0, -w);
    }
    while(bfs()) update();
    cout<<maxx<<' '<<minn;
    return 0;
}