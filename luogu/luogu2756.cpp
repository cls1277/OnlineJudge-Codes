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

const LL maxn = 105;
int n , m;
struct Edge {
	int to , next;
};
Edge e[maxn*maxn];
int head[maxn] , tot , a[maxn] , ans;
bitset<maxn>vis;

void add(int x , int y) {
	tot++;
	e[tot].next = head[x];
	e[tot].to = y;
	head[x] = tot;
	return ;
}

bool find(int x) {
	Eo(i,x,e) {
		int v=e[i].to;
		if(vis[v]) continue;
		vis[v]=1;
		if(!a[v]||find(a[v])) {
			a[v]=x;
			return true;	
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>m>>n;
	while(1) {
		int x,y; cin>>x>>y;
		if(x==-1&&y==-1) break;
		add(x,y);
	}
	Fo(i,1,n) {
		vis.reset();
		if(find(i)) ans++;
	}
	cout<<ans<<endl;
	Fo(i,m+1,n)
		if(a[i])
			cout<<a[i]<<" "<<i<<endl;
	return 0;
}

