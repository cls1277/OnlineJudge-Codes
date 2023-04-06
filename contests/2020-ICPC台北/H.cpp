//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Eo2(i,x,_) for(LL i=head2[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 1e4+5;
const LL maxm = 5e5+5;

LL n, m;
struct Edge {
    LL to, next, len;
};
Edge e[maxm<<1], ed[maxn<<1];
struct E {
    LL from, to, len;
};
E o[maxm];
LL tot, tot2, head[maxn], head2[maxn], r, l=1e7;

void add(LL x, LL y, LL z) {
    tot++;
    e[tot].next = head[x];
    e[tot].len = z;
    e[tot].to = y;
    head[x] = tot;
}

void add2(LL x, LL y, LL z) {
    tot2++;
    ed[tot2].next = head2[x];
    ed[tot2].len = z;
    ed[tot2].to = y;
    head2[x] = tot2;
}

bool vis[maxn];

void dfs(LL x, LL p) {
    Eo(i,x,e) {
        LL y = e[i].to;
        if(vis[y]||e[i].len<=p) continue;
        vis[y] = 1;
        dfs(y, p);
    }
}

bool judge(LL p) {
    Fo(i,1,n) vis[i] = 0;
    vis[1] = 1;
    dfs(1, p);
    Fo(i,1,n)
        if(!vis[i])
            return false;
    return true;
}

LL fa[maxn];

LL find(LL x) {
    while(x!=fa[x]) x = fa[x] = fa[fa[x]];
    return x;
}

bool cmp(const E &a, const E &b) {
    return a.len<b.len;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m;
    Fo(i,1,m) {
        LL x, y, z; cin>>x>>y>>z;
        add(x, y, z);
        add(y, x, z);
        r = max(r, z);
        l = min(l, z);
        o[i] = {x, y, z};
    }
    while(l<r) {
        LL mid=(l+r+1)>>1;
        if(judge(mid)) l = mid;
        else r = mid-1;
    }
    // cout<<l;
    sort(o+1, o+m+1, cmp);
    // cout<<o[1].len;
    Fo(i,1,n) fa[i] = i;
    Fo(i,1,m) {
        if(o[i].len<=l) continue;
        LL fx=find(o[i].from), fy=find(o[i].to);
        if(fx==fy) continue;
        fa[fx] = fy;
        add2(o[i].from, o[i].to, o[i].len);
        add2(o[i].to, o[i].from, o[i].len);
    }
    Fo(i,1,n) {
        cout<<i<<":";
        Eo2(j,i,ed) {
            cout<<ed[j].to<<' ';
        }
        cout<<endl;
    }
    return 0;
}
