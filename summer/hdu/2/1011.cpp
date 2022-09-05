//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'
#define ls x<<1
#define rs x<<1|1

const LL maxn = 2e5+5;
LL n, q, a[maxn];

struct Seg {
    LL l, r;
    LL ans1, ans2;//++-- +-+-
    LL a[10];
    //0 1 2  3   4  5  6   7   8   9
    //+ - ++ +- -+ -- +-- ++- +-+ -+-
    Seg() {
        ans1 = ans2 = -1e18;
        Fo(i,0,9) a[i] = -1e18;
    }
}tree[maxn<<2];

Seg operator + (const Seg &x, const Seg &y) {
    Seg z;
    Fo(i,0,9) z.a[i] = max(x.a[i], y.a[i]);
    z.a[2] = max(z.a[2], x.a[0]+y.a[0]);
    z.a[3] = max(z.a[3], x.a[0]+y.a[1]);
    z.a[4] = max(z.a[4], x.a[1]+y.a[0]);
    z.a[5] = max(z.a[5], x.a[1]+y.a[1]);
    z.a[6] = max({z.a[6], x.a[0]+y.a[5], x.a[3]+y.a[1]});
    z.a[7] = max({z.a[7], x.a[0]+y.a[3], x.a[2]+y.a[1]});
    z.a[8] = max({z.a[8], x.a[0]+y.a[4], x.a[3]+y.a[0]});
    z.a[9] = max({z.a[9], x.a[1]+y.a[3], x.a[4]+y.a[1]});
    z.ans1 = max({x.ans1, y.ans1, x.a[0]+y.a[6], x.a[2]+y.a[5], x.a[7]+y.a[1]});
    z.ans2 = max({x.ans2, y.ans2, x.a[0]+y.a[9], x.a[3]+y.a[3], x.a[8]+y.a[1]});
    return z;
}

void pushup(LL x) {
    Fo(i,0,9) tree[x].a[i] = max(tree[ls].a[i], tree[rs].a[i]);
    tree[x].a[2] = max(tree[x].a[2], tree[ls].a[0]+tree[rs].a[0]);
    tree[x].a[3] = max(tree[x].a[3], tree[ls].a[0]+tree[rs].a[1]);
    tree[x].a[4] = max(tree[x].a[4], tree[ls].a[1]+tree[rs].a[0]);
    tree[x].a[5] = max(tree[x].a[5], tree[ls].a[1]+tree[rs].a[1]);
    tree[x].a[6] = max({tree[x].a[6], tree[ls].a[0]+tree[rs].a[5], tree[ls].a[3]+tree[rs].a[1]});
    tree[x].a[7] = max({tree[x].a[7], tree[ls].a[0]+tree[rs].a[3], tree[ls].a[2]+tree[rs].a[1]});
    tree[x].a[8] = max({tree[x].a[8], tree[ls].a[0]+tree[rs].a[4], tree[ls].a[3]+tree[rs].a[0]});
    tree[x].a[9] = max({tree[x].a[9], tree[ls].a[1]+tree[rs].a[3], tree[ls].a[4]+tree[rs].a[1]});
    tree[x].ans1 = max({tree[ls].ans1, tree[rs].ans1, tree[ls].a[0]+tree[rs].a[6], tree[ls].a[2]+tree[rs].a[5], tree[ls].a[7]+tree[rs].a[1]});
    tree[x].ans2 = max({tree[ls].ans2, tree[rs].ans2, tree[ls].a[0]+tree[rs].a[9], tree[ls].a[3]+tree[rs].a[3], tree[ls].a[8]+tree[rs].a[1]});
}

void build(LL x, LL l, LL r) {
    tree[x].l = l; tree[x].r = r;
    tree[x].ans1 = tree[x].ans2 = -1e18;
    Fo(i,0,9) tree[x].a[i] = -1e18;
    if(l==r) {
        tree[x].a[0] = a[l];
        tree[x].a[1] = -a[l];
        return ;
    }
    LL mid = (l+r)>>1;
    build(ls, l, mid);
    build(rs, mid+1, r);
    pushup(x);
}

Seg query(LL x, LL l, LL r) {
    if(l<=tree[x].l&&r>=tree[x].r) return tree[x];
    LL mid = (tree[x].l+tree[x].r)>>1;
    Seg res;
    if(l<=mid) res = res+query(ls, l, r);
    if(r>mid) res = res+query(rs, l, r);
    return  res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    LL t; cin>>t;
    while(t--) {
        // Ms(tree, 0);
        cin>>n>>q;
        Fo(i,1,n) {
            cin>>a[i];
            a[i] *= a[i];
        }
        build(1, 1, n);
        while(q--) {
            LL l, r; cin>>l>>r;
            Seg ans = query(1, l, r);
            cout<<max(ans.ans1, ans.ans2)<<endl;
        }
    }
    return 0;
}
