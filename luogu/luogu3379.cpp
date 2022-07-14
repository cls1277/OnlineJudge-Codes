//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 5e5+5;

struct Edge {
    LL to, next;
}e[maxn<<1];

LL tot, head[maxn], fa[maxn], ans[maxn], ind[maxn];
map<LL, vector<pair<LL, LL>>> q;
LL n, m, s;//n是点的个数
bool vis[maxn];

void add(LL x, LL y) {
    tot++;
    e[tot].next = head[x];
    e[tot].to = y;
    head[x] = tot;
}

LL find(LL x) {
    while(x!=fa[x]) {
        x = fa[x] = fa[fa[x]];
    }
    return x;
}

void Union(LL x, LL y) {
    LL fx=find(x), fy=find(y);
    fa[fx] = fy;
}

void tarjan(LL x, LL f) {
    Eo(i, x, e) {
        LL v = e[i].to;
        if(v==f) continue;
        tarjan(v, x);
        Union(v, x);
    }
    vis[x] = 1;
    for(auto it:q[x]) {
        if(vis[it.second]) {
//            cout<<x<<' '<<it.second<<' '<<find(it.second)<<endl;
            ans[it.first] = find(it.second);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m>>s;
    Fo(i,1,n) fa[i] = i;
    Fo(i,2,n) {
        LL x, y; cin>>x>>y;
        add(y, x);
        add(x, y);
        // ind[y]++;
    }
    Fo(i,1,m) {
        LL a, b; cin>>a>>b;
        q[a].push_back({i, b});
        q[b].push_back({i, a});
    }
    tarjan(s, s);
    Fo(i,1,m) cout<<ans[i]<<endl;
    return 0;
}
