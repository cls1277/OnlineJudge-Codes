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
LL n , m , s , t , a[maxn][maxn]; 

struct Edge {
	LL to , next , len;
};
Edge e[5005*2];
LL head[maxn] , tot , dis[maxn] , pre[maxn] , ans;
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
	vis.reset();
	//Ms(dis , 0x3f);
	queue<LL>q;
	q.push(s);
	vis[s] = 1;
	dis[s] = INF;
	while(!q.empty()) {
		LL u = q.front();
		if(u==t) return 1;
		q.pop();
		Eo(i,u,e) {
			LL v = e[i].to;
			if(e[i].len<=0||vis[v]) continue;
			dis[v] = min(dis[u],e[i].len);
			pre[v] = i;
			q.push(v);
			vis[v] = 1;
			//if(v==t) return 1;
		}
	}
	return 0;
}

void update() {
	LL x = t;
	while(x!=s) {
		LL v=pre[x];
		e[v].len-=dis[t];
		e[v^1].len+=dis[t];
		x=e[v^1].to;
	}
	ans+=dis[t];
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
		LL x , y , z;
		cin>>x>>y>>z;
		if(!a[x][y]) {
			add(x , y , z);
			a[x][y] = tot;
			add(y , x , 0);
		} else e[a[x][y]].len+=z;
	}
	/*Fo(i,1,n) {
		Eo(j,i,e)
			cout<<e[j].to<<" ";
		cout<<endl;
	}*/
	while(bfs()) {
		update();
	}
	cout<<ans;
	return 0;
}

