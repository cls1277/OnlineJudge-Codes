//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

#define ls (x<<1)
#define rs (x<<1|1)

const LL maxn = 4e5+5;
LL n, xx[maxn];

struct Line {
    LL x1, x2, y, flag;
    bool operator < (const Line & x) {
        return y<x.y;
    }
}l[maxn];

struct Seg {
    LL l, r, sum, len;
} tree[maxn<<2];

void build(LL x, LL l, LL r) {
    tree[x].l=l; tree[x].r=r;
    tree[x].sum = tree[x].len = 0;
    if(l==r) return ;
    LL mid = (l+r)>>1;
    build(ls, l, mid);
    build(rs, mid+1, r);
}

void updateLen(LL x) {
    if(tree[x].sum) tree[x].len = xx[tree[x].r+1]-xx[tree[x].l];
    else tree[x].len = tree[ls].len+tree[rs].len;
}

void update(LL x, LL l, LL r, LL flag) {
	if(l>=xx[tree[x].r+1]||r<=xx[tree[x].l]) return ;
    if(l<=xx[tree[x].l]&&r>=xx[tree[x].r+1]) {
        tree[x].sum += flag;
        updateLen(x);
        return ;
    }
	update(ls, l, r, flag);
	update(rs, l, r, flag);
    updateLen(x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n;
    Fo(i,1,n) {
        LL a, b, c, d; cin>>a>>b>>c>>d;
        l[2*i-1] = {a, c, b, 1};
        l[2*i] = {a, c, d, -1};
        xx[2*i-1] = a;
        xx[2*i] = c;
    }
    n<<=1;
    sort(l+1, l+n+1);
    sort(xx+1, xx+n+1);
    LL tot = unique(xx+1, xx+n+1)-xx-1;
    build(1, 1, tot-1);
    LL ans = 0;
    Fo(i,1,n-1) {
        update(1, l[i].x1, l[i].x2, l[i].flag);
        ans += tree[1].len*(l[i+1].y-l[i].y);
    }
    cout<<ans;
    return 0;
}
