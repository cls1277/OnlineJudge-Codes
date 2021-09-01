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
#define PI adis(-1)
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

const LL maxn = 5e3+5;
const LL maxm = 5e4+5;
int n , m , s , t;
struct Edge {
	int to , next , len , cost;
};
Edge e[maxm*2];
int head[maxn] , tot;
int mf , mc , dis[maxn] , len[maxn] , pre[maxn];
bitset<maxn>vis;

void add(int x , int y , int z , int w) {
	tot++;
	e[tot].next = head[x];
	e[tot].to = y;
	e[tot].len = z;
	e[tot].cost = w;
	head[x] = tot;
	return ;
}

int spfa() {
	queue<int>q;
	vis.reset();
	Ms(dis,0x3f);
	q.push(s);
	vis[s]=1;
	dis[s]=0;
	len[s]=INF;
	while(!q.empty()) {
		int u=q.front();
		vis[u] = 0;
		q.pop();
		Eo(i,u,e) {
			if(e[i].len==0) continue;
			int v = e[i].to;
			if(dis[v]>dis[u]+e[i].cost) {
				dis[v] = dis[u]+e[i].cost;
				len[v] = min(len[u] , e[i].len);
				pre[v] = i;
				if(!vis[v]) {
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
	if(dis[t]==1061109567) return 0;
	return 1;
}

void mcmf() {
	while(spfa()) {
		mf+=len[t];
		mc+=len[t]*dis[t];
		int x = t;
		while(x!=s) {
			int v=pre[x];
			e[v].len-=len[t];
			e[v^1].len+=len[t];
			x = e[v^1].to;
		}
	}
	return ;
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>n>>m>>s>>t;
	tot=1;
	Fo(i,1,m) {
		int x , y , z , w;
		cin>>x>>y>>z>>w;
		add(x , y , z , w);
		add(y , x , 0 , -w);
	}
	mcmf();
	cout<<mf<<" "<<mc;
	return 0;
}

