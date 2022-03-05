//By cls1277
#ifdef ONLINE_JUDGE
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#else
#include<bits/stdc++.h>
#endif
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

const LL maxn = 1e5+5;
LL n;

struct Node {
    LL to, next;
}e[maxn<<1];

LL tot, head[maxn];
vector<LL>a;

void add(LL x, LL y) {
    tot++;
    e[tot].next = head[x];
    e[tot].to = y;
    head[x] = tot;
    return ;
}

LL deep[maxn], sz[maxn], son[maxn], fa[maxn];

void dfs1(LL x, LL f, LL d) {
    deep[x] = d;
    fa[x] = f;
    sz[x] = 1;
    Eo(i,x,e) {
        LL v=e[i].to;
        if(v==f) continue;
        dfs1(v, x, d+1);
        sz[x] += sz[v];
        if(sz[v]>sz[son[x]]) son[x]=v;
    }
    return ;
}

LL id[maxn], cnt, top[maxn];

void dfs2(LL x, LL t) {
    id[x] = ++cnt;
    top[x] = t;
    if(!son[x]) return;
    dfs2(son[x], t);
    Eo(i,x,e) {
        LL v=e[i].to;
        if(v==fa[x]||v==son[x]) continue;
        dfs2(v, v);
    }
    return ;
}

struct Seg {
    LL l, r, sum, lazy;
}tree[maxn<<2];

void build(LL x, LL l, LL r) {
    tree[x].l=l; tree[x].r=r;
    if(l==r) {
        tree[x].sum = 0;
        tree[x].lazy = 0;
        return ;
    }
    LL mid=(l+r)>>1;
    build(ls, l, mid);
    build(rs, mid+1, r);
    return ;
}

void pushdown(LL x) {
    tree[ls].lazy += tree[x].lazy;
    tree[rs].lazy += tree[x].lazy;
    tree[ls].sum += tree[x].lazy*(tree[ls].r-tree[ls].l+1);
    tree[rs].sum += tree[x].lazy*(tree[rs].r-tree[rs].l+1);
    tree[x].lazy = 0;
    return ;
}

void pushup(LL x) {
    tree[x].sum = tree[ls].sum + tree[rs].sum;
    return ;
}

void update(LL x, LL l, LL r, LL k) {
    if(l<=tree[x].l&&r>=tree[x].r) {
        tree[x].lazy += k;
        tree[x].sum += k*(tree[x].r-tree[x].l+1);
        return ;
    }
    pushdown(x);
    LL mid=(tree[x].l+tree[x].r)>>1;
    if(l<=mid) update(ls, l, r, k);
    if(r>mid) update(rs, l, r, k);
    pushup(x);
    return ;
}

LL query(LL x, LL l, LL r) {
    if(l<=tree[x].l&&r>=tree[x].r) {
        return tree[x].sum;    
    }
    pushdown(x);
    LL mid=(tree[x].l+tree[x].r)>>1, res=0;
    if(l<=mid) res+=query(ls, l, r);
    if(r>mid) res+=query(rs, l, r);
    return res;
}

void upd_road(LL x, LL y, LL z) {
    while(top[x]!=top[y]) {
        if(deep[top[x]]<deep[top[y]])
            swap(x,y);
        update(1,id[top[x]],id[x],z);
        x = fa[top[x]];
    }
    if(deep[x]>deep[y]) swap(x,y);
    update(1,id[x],id[y],z);
    return ;
}

LL query_road(LL x, LL y) {
    LL res=0;
    while(top[x]!=top[y]) {
        if(deep[top[x]]<deep[top[y]])
            swap(x,y);
        res += query(1,id[top[x]],id[x]);
        x = fa[top[x]];
    }
    if(deep[x]>deep[y]) swap(x,y);
    res += query(1,id[x],id[y]);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n;
    Fo(i,1,n) {
        LL x; cin>>x;
        a.push_back(x);
    }
    Fo(i,1,n-1) {
        LL x,y; cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    dfs1(1,0,1);
    dfs2(1,1);
    // Fo(i,1,n) cout<<i<<":"<<id[i]<<endl;
    build(1,1,n);
    for(int i=0; i<a.size()-1; i++) {
        upd_road(a[i],a[i+1],1);
    }
    cout<<query_road(1,1)<<endl;
    Fo(i,2,n) cout<<query_road(i,i)-1<<endl;
    return 0;
}