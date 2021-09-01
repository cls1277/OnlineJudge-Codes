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

const LL maxn = 2e5+5;
int n , m , len , a[maxn] , b[maxn] , root[maxn] , cnt;
int ls[maxn<<5] , rs[maxn<<5] , sum[maxn<<5];

int build(int l , int  r) {
	int rt = ++cnt;
	if(l==r) return rt;
	int mid=(l+r)>>1;
	ls[rt] = build(l,mid);
	rs[rt] = build(mid+1,r);
	return rt;
}

int update(int rt , int l , int r , int x) {
	int op = ++cnt;
	ls[op]=ls[rt]; rs[op]=rs[rt]; sum[op]=sum[rt]+1;
	if(l==r) return op;
	int mid=(l+r)>>1;
	if()
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>n>>m;
	Fo(i,1,n) {
		cin>>a[i];
		b[i] = a[i];
	}
	sort(b+1,b+n+1);
	len=unique(b+1,b+n+1)-b-1;
	Fo(i,1,n) a[i]=lower_bound(b+1,b+len+1,a[i])-b;
	root[0]=build(1,len);
	Fo(i,1,n) root[i]=update(root[i-1],1,len,a[i]);
	return 0;
}

