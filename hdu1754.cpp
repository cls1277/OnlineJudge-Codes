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

const LL maxn = 2e5+5;
struct Seg {
	LL l , r , max;
};
Seg tree[4*maxn];
LL T , n , m , a[maxn]; 

void pushup(LL num) {
	tree[num].max = max(tree[num<<1].max,tree[num<<1|1].max);
}

void build(LL num , LL l , LL r) {
	tree[num].l = l;
	tree[num].r = r;
	if(l==r) {
		tree[num].max = a[l];
		return ;
	}
	LL mid = (l+r)>>1;
	build(num<<1 , l , mid);
	build(num<<1|1 , mid+1 , r);
	pushup(num);
}

void update(LL num , LL l , LL d) {
	if(tree[num].l==l&&tree[num].r==l) {
		tree[num].max =d;
		return ;
	}
	LL mid = (tree[num].l+tree[num].r)>>1;
	if(l<=mid) update(num<<1 , l , d);
	if(l>mid) update(num<<1|1 , l , d);
	pushup(num);
}

LL query(LL num , LL l , LL r) {
	if(l<=tree[num].l&&r>=tree[num].r)
		return tree[num].max;
	LL mid = (tree[num].l+tree[num].r)>>1 , ans=0;
	if(l<=mid) ans=max(query(num<<1,l,r),ans);
	if(r>mid) ans=max(query(num<<1|1,l,r),ans);
	return ans;
}

int main() {
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	while(cin>>n>>m) {
		Fo(i,1,n) a[i]=read();
		build(1,1,n);
		string op;
		LL x , y;
		Fo(i,1,m) {
			cin>>op;
			if(op[0]=='Q') {
				x=read(); y=read();
				printf("%lld\n",query(1,x,y));
			} else if(op[0]=='U') {
				x=read(); y=read();
				update(1,x,y);
			}
		}
	}
	return 0;
}

