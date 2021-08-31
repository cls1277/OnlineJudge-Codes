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

const LL maxn = 5e4+5;
struct Seg {
	LL l , r , sum;
};
Seg tree[4*maxn];
LL T , n , a[maxn] , tt; 

void pushup(LL num) {
	tree[num].sum = tree[num<<1].sum+tree[num<<1|1].sum;
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

void update(LL num , LL l , LL d) {
	if(tree[num].l==l&&tree[num].r==l) {
		tree[num].sum += d;
		return ;
	}
	LL mid = (tree[num].l+tree[num].r)>>1;
	if(l<=mid) update(num<<1 , l , d);
	if(l>mid) update(num<<1|1 , l , d);
	pushup(num);
}

LL query(LL num , LL l , LL r) {
	if(l<=tree[num].l&&r>=tree[num].r)
		return tree[num].sum;
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
	T=read();
	//cin>>T;
	while(T--) {
		printf("Case %lld:\n",(++tt));
		//cout<<"Case "<<(++tt)<<":"<<endl;
		n=read();
		//cin>>n;
		Fo(i,1,n) a[i]=read();//cin>>a[i];
		build(1,1,n);
		string op;
		LL x , y;
		while(1) {
			cin>>op;
			if(op[0]=='Q') {
				x=read(); y=read();
				//cin>>x>>y;
				printf("%lld\n",query(1,x,y));
				//cout<<query(1,x,y)<<endl;
			} else if(op[0]=='A') {
				x=read(); y=read();
				//cin>>x>>y;
				update(1,x,y);
			} else if(op[0]=='S') {
				x=read(); y=read();
				//cin>>x>>y;
				update(1,x,-y);
			} else if(op[0]=='E') {
				Ms(tree , 0);
				break;
			}	
		}
	}
	return 0;
}

