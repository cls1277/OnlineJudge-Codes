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

const LL maxn = 205;
int n , id;
double mp[maxn][maxn] , dis[maxn] , _x[maxn] , _y[maxn];
bitset<maxn>vis;

double len(int x , int y) {
	return sqrt((_x[x]-_x[y])*(_x[x]-_x[y])+(_y[x]-_y[y])*(_y[x]-_y[y]));
}

void spfa() {
	queue<int>q;
	Fo(i,1,n) dis[i]=INF;
	vis.reset();
	q.push(1); dis[1]=0; vis[1]=1;
	while(!q.empty()) {
		int u=q.front(); q.pop(); vis[u]=0;
		Fo(i,1,n)
			if(max(dis[u],mp[u][i])<dis[i]) {
				dis[i]=max(dis[u],mp[u][i]);
				if(!vis[i]) {
					q.push(i);
					vis[i]=1;
				}
			}
	}
	return ;
}

int main() {
	//ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	while(cin>>n&&n) {
		Ms(mp,0);
		Fo(i,1,n) cin>>_x[i]>>_y[i];
		Fo(i,1,n)
			Fo(j,i+1,n)
				mp[i][j]=mp[j][i]=len(i,j);
		spfa();
		id++;
		printf("Scenario #%d\nFrog Distance = %.3f\n\n",id,dis[2]);
	}
	return 0;
}

