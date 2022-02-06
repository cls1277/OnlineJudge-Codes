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

const LL maxn = 1005;
int n , m , g[maxn][maxn] , xb[maxn] , ans  , a[maxn];
bitset<maxn>vis;
bitset<maxn>use;

void dfs(int x , int y) {
	xb[x]=y;
	Fo(i,0,n-1)
		if(g[x][i]&&!xb[i])
			dfs(i,3-y);
	return ;
}

bool find(int x) {
	Fo(i,0,n-1) {
		if(xb[i]!=2||vis[i]) continue;
		vis[i] = 1;
		if(a[i]==-1||find(a[i])) {
			a[i] = x;
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
	cin>>n>>m;
	Fo(i,1,n) a[i]=-1;
	Fo(i,1,m) {
		int x , y;
		cin>>x>>y;
		g[x][y]=g[y][x]=1;
		use[x]=use[y]=1;
	}
	Fo(i,0,n-1)
		if(!xb[i]&&use[i])
			dfs(i,1);
//	Fo(i,0,n-1) cout<<xb[i]<<" "; cout<<endl;
	Fo(i,0,n-1) {
		if(xb[i]!=1) continue;
		vis.reset();
		if(find(i)) ans++;
	}
	cout<<n-ans;
	return 0;
}
