//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 2e6+5;
LL n , m , root , mod , val[maxn];
struct Edge {
	LL to , len , next;
};
Edge e[2*maxn];
LL head[maxn] , tot;
LL deep[maxn] , sz[maxn] , fa[maxn] , son[maxn];
LL id[maxn] , num[maxn] , top[maxn] , cnt;
struct Seg {
	LL l , r , num , lazy;
};
Seg tree[4*maxn];

void add(LL x , LL y) {
	tot++;
	e[tot].next = head[x];
	e[tot].to = y;
	head[x] = tot;
}

void pushup(LL x) {
	tree[x].num = (tree[x<<1].num+tree[x<<1|1].num);
	return ;
}

void pushdown(LL x) {
	tree[x<<1].lazy += tree[x].lazy;
	tree[x<<1|1].lazy += tree[x].lazy;
	tree[x<<1].num = (tree[x<<1].num+(tree[x<<1].r-tree[x<<1].l+1)*tree[x].lazy);
	tree[x<<1|1].num = (tree[x<<1|1].num+(tree[x<<1|1].r-tree[x<<1|1].l+1)*tree[x].lazy);
	tree[x].lazy = 0;
	return ;
}

void build(LL x , LL l , LL r) {
	tree[x].l=l; tree[x].r=r;
	if(l==r) {
		tree[x].num=0;
		return ;
	}
	LL mid = (l+r)>>1;
	build(x<<1 , l , mid);
	build(x<<1|1 , mid+1 , r);
	pushup(x);
	return ;
}

void update(LL x , LL l , LL r , LL k) {
	if(l<=tree[x].l&&r>=tree[x].r) {
		tree[x].lazy += k;
		tree[x].num = (tree[x].num+(tree[x].r-tree[x].l+1)*k);
		return ;
	}
	pushdown(x);
	LL mid = (tree[x].l+tree[x].r)>>1;
	if(l<=mid) update(x<<1 , l , r , k);
	if(r>mid) update(x<<1|1 , l , r , k);
	pushup(x);
	return ;
}

LL query(LL x , LL l , LL r) {
	if(l<=tree[x].l&&r>=tree[x].r)
		return tree[x].num;
	pushdown(x);
	LL mid = (tree[x].l+tree[x].r)>>1 , ans=0;
	if(l<=mid) ans=(ans+query(x<<1,l,r));
	if(r>mid) ans=(ans+query(x<<1|1,l,r));
	return ans;
}

void dfs1(LL x , LL f , LL d) {
	deep[x] = d;
	fa[x] = f;
	sz[x] = 1;
	LL maxson = -1;
	Eo(i,x,e) {
		LL v=e[i].to;
		if(v==f) continue;
		dfs1(v , x , d+1);
		sz[x] += sz[v];
		if(sz[v]>maxson) {
			maxson = sz[v];
			son[x] = v;
		}
	}
	return ;
}

void dfs2(LL x , LL t) {
	id[x]=++cnt;
	num[cnt]=val[x];
	top[x]=t;
	if(!son[x]) return ;
	dfs2(son[x] , t);
	Eo(i,x,e) {
		LL v=e[i].to;
		if(v==fa[x]||v==son[x]) continue;
		dfs2(v,v);
	}
}

LL query_road(LL x , LL y) {
	LL ans = 0;
	while(top[x]!=top[y]) {
		if(deep[top[x]]<deep[top[y]]) swap(x,y);
		ans = (ans+query(1,id[top[x]],id[x]));
		x = fa[top[x]];
	}
	if(deep[x]>deep[y]) swap(x,y);
	ans = (ans+query(1,id[x],id[y]));
	return ans;
}

void upd_road(LL x , LL y , LL z) {
	while(top[x]!=top[y]) {
		if(deep[top[x]]<deep[top[y]]) swap(x,y);
		update(1,id[top[x]],id[x],z);
		x = fa[top[x]];
	}
	if(deep[x]>deep[y]) swap(x,y);
	update(1,id[x],id[y],z);
	return ;
}

void upd_son(LL x , LL y) {
	update(1,id[x],id[x]+sz[x]-1,y);
	return ;
}

LL query_son(LL x) {
	return query(1,id[x],id[x]+sz[x]-1);
}

LL pa[maxn][25];

LL findFa(LL x, LL y) {
    Ro(i,22,0) {
        if(deep[pa[x][i]]>=y)
            x = pa[x][i];
        if(deep[x]==y) return x;
    }
    return 1;
}

inline LL read() {
	LL x = 0, f = 1;char c = getchar();
	while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
	while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
	return x * f;
}

int main() {
	// ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
    freopen("out.txt","w",stdout);
	#endif
    n=read(); // cin>>n;
    Fo(i,1,n-1) {
        LL x, y; x=read(); y=read(); //cin>>x>>y;
        add(x, y);
        add(y, x);
    }
    dfs1(1, 0, 0);
    dfs2(1, 1);
    Fo(i,1,n) pa[i][0] = fa[i];
    for(LL i=1; i<=22; i++) {
        for(LL j=1; j<=n; j++) {
            pa[j][i] = pa[pa[j][i-1]][i-1];
        }
    }
	build(1,1,n);
     Fo(i,1,n) {
         LL x; x=read(); //cin>>x;
         if(deep[i]<=x) upd_road(i, 1, 1);
         else upd_road(i, findFa(i, deep[i]-x), 1);
     }
     Fo(i,1,n) {
        //  cout<<query_road(i, i)<<' ';
        printf("%lld ",query_road(i, i));
     }
	return 0;
}
