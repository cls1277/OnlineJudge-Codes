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

const LL maxn = 1e4+5;
const LL MAXN = 1e7+5;
LL n , m; 
struct Seg {
	LL to , next , len;
};
Seg e[2*maxn];
LL head[maxn] , tot , q[105];
LL root , sz[maxn] , maxp[maxn] , sum , save[maxn] , ans[105] , dis[maxn];
bool jud[MAXN];
bitset<maxn>vis;

void add(LL x , LL y , LL z) {
	tot++;
	e[tot].next = head[x];
	e[tot].to = y;
	e[tot].len = z;
	head[x] = tot;
	return ;
}

void getroot(LL x , LL f) {
	sz[x]=1; maxp[x]=0;
	for(int i=head[x]; i; i=e[i].next) {
		LL v=e[i].to;
		if(f==v||vis[v]) continue;
		getroot(v,x);
		sz[x]+=sz[v];
		maxp[x]=max(maxp[x],sz[v]);
	}
	maxp[x]=max(maxp[x],sum-maxp[x]);
	if(maxp[x]<maxp[root]) root=x;
	return ;
}

void getlen(LL x , LL f) {
	if(dis[x]>MAXN) return ;
	save[++save[0]]=dis[x];
	for(int i=head[x]; i; i=e[i].next) {
		LL v=e[i].to;
		if(vis[v]||v==f) continue;
		dis[v]=dis[x]+e[i].len;
		getlen(v,x);
	}
	return ;
}

void devide(LL x) {
	int tot=0 , temp[maxn];
	for(int i=head[x]; i; i=e[i].next) {
		LL v=e[i].to;
		if(vis[v]) continue;
		save[0]=0;
		dis[v]=e[i].len;
		getlen(v,x);
		Ro(j,save[0],1)
			Fo(k,1,m) {
				if(q[k]>=save[j])
					ans[k] |= jud[q[k]-save[j]];				
			}
		Ro(j,save[0],1) {
			jud[save[j]] = 1;
			temp[++tot]=save[j];			
		}
	}
	Fo(i,1,tot) jud[temp[i]]=0;
	return ;
}

void sol(LL x) {
	vis[x]=jud[0]=1;
	devide(x);
	for(int i=head[x]; i; i=e[i].next) {
		LL v=e[i].to;
		if(vis[v]) continue;
		sum=sz[v];
		root=0; maxp[root]=INF;
		getroot(v,0);
		sol(root);
	}
	return ;
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>n>>m;
	Fo(i,1,n-1) {
		LL x , y , z;
		cin>>x>>y>>z;
		add(x,y,z); add(y,x,z);
	}
	Fo(i,1,m) cin>>q[i];
	root=0; maxp[root]=sum=n;
	getroot(1,0);
	sol(root);
	Fo(i,1,m)	cout<<(ans[i]?"AYE":"NAY")<<endl;
	return 0;
}

