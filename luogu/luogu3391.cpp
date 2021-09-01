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

#define ls tree[u].son[0]
#define rs tree[u].son[1]
const LL maxn = 1e5+5;
int n , m , val[maxn];
struct Tree {
	int fa , son[2] , sz , val , tag;
};
Tree tree[maxn];
int root , id;

void update(int u) {
	if(u) tree[u].sz=tree[ls].sz+tree[rs].sz+1;
	return ;
}

void pushdown(int u) {
	if(u&&tree[u].tag) {
		tree[ls].tag^=1;
		tree[rs].tag^=1;
		swap(ls,rs);
		tree[u].tag=0;
	}
	return ;
}

int getson(int u) {
	return tree[tree[u].fa].son[1]==u;
}

void rotate(int u) {
	int f=tree[u].fa , g=tree[f].fa;
	int now = getson(u);
	tree[f].son[now]=tree[u].son[now^1];
	tree[tree[f].son[now]].fa=f;
	tree[u].son[now^1]=f;
	tree[f].fa=u;
	tree[u].fa=g;
	if(g) tree[g].son[tree[g].son[1]==f]=u;
	update(u);
	update(f);
	return ;
}

void Splay(int u , int g) {
	for(int f; (f=tree[u].fa)!=g;rotate(u))
		if(tree[f].fa!=g)
			rotate(getson(f)==getson(u)?f:u);
	if(!g) root=u;
	return ;
}

int build(int l , int r , int f) {
	if(l>r) return 0;
	int mid = (l+r)>>1;
	int now = ++id;
	tree[now].fa = f;
	tree[now].val = val[mid];
	tree[now].son[0] = build(l,mid-1,now);
	tree[now].son[1] = build(mid+1,r,now);
	update(now);
	return now;
}

int find(int &u , int v) {
	if(!u) return INF;
	pushdown(u);
	if(tree[ls].sz>=v) return find(ls,v);
	if(tree[ls].sz+1>=v) return u;
	return find(rs,v-tree[ls].sz-1);
}

void reverse(int l , int r) {
	l=find(root,l),	r=find(root,r);
	Splay(l,0); Splay(r,l);
	tree[tree[tree[root].son[1]].son[0]].tag^=1;
	return ;
}

void dfs(int u) {
	pushdown(u);
	if(ls) dfs(ls);
	if(tree[u].val!=INF&&tree[u].val!=-INF) cout<<tree[u].val<<" ";
	if(rs) dfs(rs);
	return ;
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>n>>m;
	val[0]=-INF; val[n+1]=INF;
	Fo(i,1,n) val[i]=i;
	root=build(0,n+1,0);
	Fo(i,1,m) {
		int l , r;
		cin>>l>>r;
		reverse(l,r+2);
	}
	dfs(root);
	return 0;
}

