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

const int maxn = 2e4+5;
struct Edge {
	int to , next , len;
};
int tot , head[maxn] , n , sum , root , maxp[maxn] , sz[maxn];
int p[5] , dis[maxn] , ans;
bitset<maxn>vis;
Edge e[maxn*2];

int gcd(int x , int y) {
	return y?gcd(y,x%y):x;
}

void add(int x , int y , int z) {
	tot++;
	e[tot].next = head[x];
	e[tot].to = y;
	e[tot].len = z;
	head[x] = tot;
}

void getroot(int x , int f) {
	sz[x]=1; maxp[x]=0;
	Eo(i,x,e) {
		int v=e[i].to;
		if(v==f||vis[v]) continue;
		getroot(v,x);
		sz[x]+=sz[v];
		maxp[x]=max(maxp[x],maxp[v]);
	}
	maxp[x]=max(maxp[x],sum-maxp[x]);
	if(maxp[x]<maxp[root]) root=x;
	return ;
}

void getlen(int x , int f) {
	p[dis[x]%3]++;
	Eo(i,x,e) {
		int v=e[i].to;
		if(v==f||vis[v]) continue;
		dis[v]=(dis[x]+e[i].len)%3;
		getlen(v,x);
	}
	return ;
}

int divide(int x , int l) {
	dis[x]=l;
	p[0]=p[1]=p[2]=0;
	getlen(x,0);
	return p[0]*p[0]+p[1]*p[2]*2;
}

void sol(int x) {
	ans+=divide(x,0);
	vis[x]=1;
	Eo(i,x,e) {
		int v=e[i].to;
		if(vis[v]) continue;
		ans-=divide(v,e[i].len);
		sum=sz[v]; root=0; maxp[root]=INF;
		getroot(v,x);
		sol(root);
	}
	return ;
}

int main() {
	//ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	//cin>>n;
	n=read();
	Fo(i,1,n-1) {
		int x , y , z;
		x=read(); y=read(); z=read();
		//cin>>x>>y>>z;
		z%=3;
		add(x,y,z);
		add(y,x,z);
	}
	root=0; maxp[root]=sum=n;
	getroot(1,0);
	sol(1);
	int res=gcd(n*n,ans);
	printf("%d/%d",ans/res,n*n/res);
	//cout<<ans/res<<"/"<<n*n/res;
	return 0;
}

