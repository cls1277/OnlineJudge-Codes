//By cls1277
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<stack>
#include<sstream>
#include<set>
#include<cassert>
#include<bitset>
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
inline LL read() {
	LL x = 0, f = 1;char c = getchar();
	while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
	while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
	return x * f;
}

const LL maxn = 1e5+5;
int n , m , root , mod , val[maxn];
struct Edge {
	int to , len , next;
};
Edge e[2*maxn];
int head[maxn] , tot;
int deep[maxn] , sz[maxn] , fa[maxn] , son[maxn];
int id[maxn] , num[maxn] , top[maxn] , cnt;
struct Seg {
	int l , r , num , lazy;
};
Seg tree[4*maxn];

void add(int x , int y) {
	tot++;
	e[tot].next = head[x];
	e[tot].to = y;
	head[x] = tot;
}

void pushup(int x) {
	tree[x].num = (tree[x<<1].num+tree[x<<1|1].num)%mod;
	return ;
}

void pushdown(int x) {
	tree[x<<1].lazy += tree[x].lazy;
	tree[x<<1|1].lazy += tree[x].lazy;
	tree[x<<1].num = (tree[x<<1].num+(tree[x<<1].r-tree[x<<1].l+1)*tree[x].lazy%mod)%mod;
	tree[x<<1|1].num = (tree[x<<1|1].num+(tree[x<<1|1].r-tree[x<<1|1].l+1)*tree[x].lazy%mod)%mod;
	tree[x].lazy = 0;
	return ;
}

void build(int x , int l , int r) {
	tree[x].l=l; tree[x].r=r;
	if(l==r) {
		tree[x].num=num[l]%mod;
		return ;
	}
	int mid = (l+r)>>1;
	build(x<<1 , l , mid);
	build(x<<1|1 , mid+1 , r);
	pushup(x);
	return ;
}

void update(int x , int l , int r , int k) {
	if(l<=tree[x].l&&r>=tree[x].r) {
		tree[x].lazy += k;
		tree[x].num = (tree[x].num+(tree[x].r-tree[x].l+1)*k)%mod;
		return ;
	}
	pushdown(x);
	int mid = (tree[x].l+tree[x].r)>>1;
	if(l<=mid) update(x<<1 , l , r , k);
	if(r>mid) update(x<<1|1 , l , r , k);
	pushup(x);
	return ;
}

int query(int x , int l , int r) {
	if(l<=tree[x].l&&r>=tree[x].r)
		return tree[x].num%mod;
	pushdown(x);
	int mid = (tree[x].l+tree[x].r)>>1 , ans=0;
	if(l<=mid) ans=(ans+query(x<<1,l,r)%mod)%mod;
	if(r>mid) ans=(ans+query(x<<1|1,l,r)%mod)%mod;
	return ans%mod;
}

void dfs1(int x , int f , int d) {
	deep[x] = d;
	fa[x] = f;
	sz[x] = 1;
	int maxson = -1;
	Eo(i,x,e) {
		int v=e[i].to;
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

void dfs2(int x , int t) {
	id[x]=++cnt;
	num[cnt]=val[x];
	top[x]=t;
	if(!son[x]) return ;
	dfs2(son[x] , t);
	Eo(i,x,e) {
		int v=e[i].to;
		if(v==fa[x]||v==son[x]) continue;
		dfs2(v,v);
	}
}

int query_road(int x , int y) {
	int ans = 0;
	while(top[x]!=top[y]) {
		if(deep[top[x]]<deep[top[y]]) swap(x,y);
		ans = (ans+query(1,id[top[x]],id[x])%mod)%mod;
		x = fa[top[x]];
	}
	if(deep[x]>deep[y]) swap(x,y);
	ans = (ans+query(1,id[x],id[y])%mod)%mod;
	return ans%mod;
}

void upd_road(int x , int y , int z) {
	while(top[x]!=top[y]) {
		if(deep[top[x]]<deep[top[y]]) swap(x,y);
		update(1,id[top[x]],id[x],z);
		x = fa[top[x]];
	}
	if(deep[x]>deep[y]) swap(x,y);
	update(1,id[x],id[y],z);
	return ;
}

void upd_son(int x , int y) {
	update(1,id[x],id[x]+sz[x]-1,y);
	return ;
}

int query_son(int x) {
	return query(1,id[x],id[x]+sz[x]-1)%mod;
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>n>>m>>root>>mod;
	Fo(i,1,n) cin>>val[i];
	Fo(i,1,n-1) {
		int x , y;
		cin>>x>>y;
		add(x , y);
		add(y , x);
	}
	dfs1(root , 0 , 1);
	dfs2(root , root);
	build(1,1,n);
	Fo(i,1,m) {
		int op , x , y , z;
		cin>>op;
		if(op==1) {
			cin>>x>>y>>z;
			upd_road(x,y,z);
		} if(op==2) {
			cin>>x>>y;
			cout<<query_road(x,y)<<endl;
		} if(op==3) {
			cin>>x>>y;
			upd_son(x,y);
		} if(op==4) {
			cin>>x;
			cout<<query_son(x)<<endl;
		}
	}
	return 0;
}

