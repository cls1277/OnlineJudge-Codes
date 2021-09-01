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

const LL maxn = 2e4+5;
const LL maxm = 1e5+5;
int n , m;
struct Edge {
	int to , next;
};
Edge e[maxm*2];
int head[maxn] , tot;
int dfn[maxn] , low[maxn] , idx , ans;
bitset<maxn>is;

void add(int x , int y) {
	tot++;
	e[tot].next = head[x];
	e[tot].to = y;
	head[x] = tot;
	return ;
}

void tarjan(int u , int f) {
	low[u] = dfn[u] = ++idx;
	int cnt=0;
	Eo(i,u,e) {
		int v=e[i].to;
		if(v==f) continue;
		if(!dfn[v]) {
			tarjan(v,u);
			low[u] = min(low[u] , low[v]);
			if(low[v]>=dfn[u]&&u!=f)
				is[u] = 1;
			if(u==f) cnt++;
		}
		low[u] = min(low[u] , dfn[v]);
	}
	if(cnt>1&&u==f)
		is[u] = 1;
	return ;
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>n>>m; 
	Fo(i,1,m) {
		int x , y;
		cin>>x>>y;
		add(x , y);
		add(y , x);
	}
	Fo(i,1,n)
		if(!dfn[i])
			tarjan(i,i);
	Fo(i,1,n)
		if(is[i])
			ans++;
	cout<<ans<<endl;
	Fo(i,1,n)
		if(is[i])
			cout<<i<<" ";
	return 0;
}

