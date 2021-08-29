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
#define Ms(a,b) memset((a),(b),sizeof(a))
#define lowbit(_) _&(-_)
inline LL read() {
	LL x = 0, f = 1;char c = getchar();
	while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
	while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
	return x * f;
}

const LL maxn = 1e5+5;
struct Seg {
	LL l , r , sum , lazy;
};
Seg tree[4*maxn];
LL n , a[maxn] , m; 

void pushup(LL num) {
	tree[num].sum = tree[num<<1].sum+tree[num<<1|1].sum;
}

void pushdown(LL num) {
	tree[num<<1].lazy += tree[num].lazy;
	tree[num<<1|1].lazy += tree[num].lazy;
	tree[num<<1].sum += (tree[num<<1].r-tree[num<<1].l+1)*tree[num].lazy;
	tree[num<<1|1].sum += (tree[num<<1|1].r-tree[num<<1|1].l+1)*tree[num].lazy;
	tree[num].lazy = 0;
}

void build(LL num , LL l , LL r) {
	tree[num].l = l;
	tree[num].r = r;
	if(l==r) {
		tree[num].sum = a[l];
		return ;
	}
	LL mid = (l+r)>>1;
	build(num<<1 , l , mid);
	build(num<<1|1 , mid+1 , r);
	pushup(num);
}

void update(LL num , LL l , LL r , LL d) {
	if(l<=tree[num].l&&r>=tree[num].r) {
		tree[num].lazy += d;
		tree[num].sum += (tree[num].r-tree[num].l+1)*d;
		return ;
	}
	pushdown(num);
	LL mid = (tree[num].l+tree[num].r)>>1;
	if(l<=mid) update(num<<1 , l , r , d);
	if(r>mid) update(num<<1|1 , l , r , d);
	pushup(num);
}

LL query(LL num , LL l , LL r) {
	if(l<=tree[num].l&&r>=tree[num].r)
		return tree[num].sum;
	pushdown(num);
	LL mid = (tree[num].l+tree[num].r)>>1 , ans=0;
	if(l<=mid) ans+=query(num<<1,l,r);
	if(r>mid) ans+=query(num<<1|1,l,r);
	return ans;
}

int main() {
	//ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	n=read(); m=read();
	Fo(i,1,n) a[i]=read();
	build(1,1,n);
	Fo(i,1,m) {
		char op;
		cin>>op;
		if(op=='C') {
			LL x , y , z;
			x=read(); y=read(); z=read();
			update(1,x,y,z);
		} else if(op=='Q') {
			LL x , y;
			x=read(); y=read();
			printf("%lld\n",query(1,x,y));
		}
	}
	return 0;
}

