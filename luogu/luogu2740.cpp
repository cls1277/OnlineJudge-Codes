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
LL n , m;
struct Edge {
	LL to , next , len;
};
Edge e[maxn*2];
LL tot , head[maxn] , d[maxn] , _head[maxn] , ans , flag;
bitset<maxn>vis;

void add(LL x , LL y , LL z) {
	tot++;
	e[tot].next = head[x];
	e[tot].to = y;
	e[tot].len = z;
	head[x] = tot;
	return ;
}

int bfs() {
	Fo(i,1,n) d[i]=-1;
	vis.reset();
	queue<LL>q;
	q.push(1);
	d[1]=0;
	vis[1] = 1;
	Fo(i,1,n) _head[i]=head[i];
	while(!q.empty()) {
		int u=q.front();
		if(u==n) return 1;
		vis[u]=0;
		q.pop();
		Eo(i,u,e) {
			int v=e[i].to;
			if(e[i].len<=0||d[v]!=-1) continue;
			d[v]=d[u]+1;
			if(!vis[v]) {
				q.push(v);
				vis[v] = 1;
			}
		}
	}
	return 0;
}

int dfs(LL x , LL low) {
	if(x==n) {
		flag = 1;
		ans += low;
		return low;
	}
	LL used=0;
	for(int i=_head[x]; i&&low; i=e[i].next) {
		LL v=e[i].to;
		_head[x] = i;
		if(e[i].len<=0||d[v]!=d[x]+1) continue;
		LL temp = dfs(v , min(low,e[i].len));
		used += temp;
		e[i].len -= temp;
		e[i^1].len += temp;
		if(used==low) break;
	}
	return used;
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	tot=1;
	cin>>m>>n;
	Fo(i,1,m) {
		LL x , y , z;
		cin>>x>>y>>z;
		add(x , y , z);
		add(y , x , 0);
	}
	while(bfs()) {
		flag = 1;
		while(flag) {
			flag = 0;
			dfs(1,INF);
		}
	}
	cout<<ans;
	return 0;
}

