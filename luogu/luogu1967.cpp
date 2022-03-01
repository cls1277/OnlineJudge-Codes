//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define PI acos(-1)
#define INF 2147483647
#define eps 1e-7
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define lowbit(_) _&(-_)
#define mk(_,__) make_pair(_,__)
#define pii pair<int,int>
#define ls x<<1
#define rs x<<1|1
#define endl '\n'
inline LL read() {
    LL x = 0, f = 1;char c = getchar();
    while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
    while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
    return x * f;
}

const LL maxn = 1e4+5;
const LL maxm = 5e4+5;

struct Seg {
    LL from , to , len;
    Seg(){}
    Seg(LL f, LL t, LL l) {
        from=f , to=t , len=l;
    }
    bool operator < (const Seg &x) {
        return len>x.len;
    }
}road[maxm];

struct Node {
    LL to , next , len;
    Node(){}
    Node(LL t, LL n, LL l) {
        to=t , next=n, len=l;
    }
}e[maxn<<1];

LL tot, head[maxn];

void add(LL x, LL y, LL z) {
    tot++;
    e[tot].next = head[x];
    e[tot].to = y;
    e[tot].len = z;
    head[x] = tot;
}

LL pa[maxn];

LL find(LL x) {
    if(pa[x]!=x)
        pa[x] = find(pa[x]);
    return pa[x];
}

LL deep[maxn], fa[maxn][25], wt[maxn][25];
bool vis[maxn];

void dfs(LL u, LL f, LL w) {
    deep[u] = deep[f]+1;
    fa[u][0] = f;
    wt[u][0] = w;
    Eo(i,u,e) {
        LL v=e[i].to;
        if(vis[v]) continue;
        vis[v] = 1;
        dfs(v, u, e[i].len);
    }
}

LL lca(LL x, LL y) {
    LL ans = INF;
    if(deep[x]<deep[y]) swap(x,y);
    Ro(i,20,0) {
        if(deep[fa[x][i]]>=deep[y]) {
            ans = min(ans, wt[x][i]);
            x = fa[x][i];
        }
        if(x==y) return ans;
    }
    Ro(i,20,0) {
        if(fa[x][i]!=fa[y][i]) {
            ans = min(ans, wt[x][i]);
            ans = min(ans, wt[y][i]);
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    ans = min(ans, wt[x][0]);
    ans = min(ans, wt[y][0]);
    return ans;
}

LL n, m;

int main() {
    ios::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    Ms(wt,0x3f);
    cin>>n>>m;
    Fo(i,1,n) pa[i]=i;
    Fo(i,1,m) {
        LL x, y, z;
        cin>>x>>y>>z;
        road[i] = Seg(x,y,z);
    }
    sort(road+1, road+m+1);
    // cout<<road[1].len<<endl;
    // LL cnt=0;
    Fo(i,1,m) {
        LL fx=find(road[i].from) , fy=find(road[i].to);
        if(fx!=fy) {
            pa[fx] = fy;
            // cnt++;
            // cout<<road[i].from<<" "<<road[i].to<<" "<<road[i].len<<endl;
            add(road[i].from, road[i].to, road[i].len);
            add(road[i].to, road[i].from, road[i].len);
            // if(cnt==n-1) break;
        }
    }
    Fo(i,1,n) {
        if(!vis[i]) {
            // cout<<i<<" ";
            vis[i] = 1;
            dfs(i,0,INF);
        }
    }
    Fo(i,1,20) {
        Fo(j,1,n) {
            fa[j][i] = fa[fa[j][i-1]][i-1];
            wt[j][i] = min(wt[j][i-1], wt[fa[j][i-1]][i-1]);
        }
    }
    // Fo(i,1,n) cout<<wt[i][1]<<" ";
    LL q; cin>>q;
    while(q--) {
        LL x, y; cin>>x>>y;
        if(find(x)!=find(y)) {
            cout<<"-1"<<endl;
            continue;
        }
        LL res = lca(x,y);
        if(res==INF) cout<<"-1"<<endl;
        else cout<<res<<endl;
    }
    // Fo(i,1,n) cout<<deep[i]<<" ";
    // cout<<deep[2];
    return 0;
}