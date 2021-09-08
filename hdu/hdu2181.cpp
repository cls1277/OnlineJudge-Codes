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

const LL maxn = 25;
int m , ans , temp[maxn];
bitset<maxn>vis;
vector<int>g[maxn];

void dfs(int x , int y[] , int z) {
	if(z==20&&x==m) {
		ans++;
		cout<<ans<<":  ";
		Fo(i,0,19)
			cout<<y[i]<<" ";
		cout<<y[20]<<endl;
		return ;
	}
	for(int i=0; i<g[x].size(); i++) {
		y[z+1] = g[x][i];
		if(vis[g[x][i]]) continue;
		vis[g[x][i]]=1;
		dfs(g[x][i] , y , z+1);
		vis[g[x][i]]=0;
	}
	return ;
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	Fo(i,1,20) {
		int x,y,z; cin>>x>>y>>z;
		g[i].push_back(x);
		g[i].push_back(y);
		g[i].push_back(z);
		sort(g[i].begin(),g[i].end());
	} 
	while(cin>>m&&m) {
		ans=0;
		vis.reset();
		temp[0]=m;
		dfs(m,temp,0);
	}
	return 0;
}

