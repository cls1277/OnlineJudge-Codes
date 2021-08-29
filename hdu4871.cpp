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
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define lowbit(_) _&(-_)
inline LL read() {
	LL x = 0, f = 1;char c = getchar();
	while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
	while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
	return x * f;
}

const int maxn = 3e4+5;
int T , n , m , K;
struct Node {
	int to , next , len;
	Node(){}
	Node(int tt , int nn , int ll) {
		to=tt , next=nn , len=ll;
	}
};
Node e[maxn];
vector<pair<int,int>>g[maxn];
vector<int>tmp[maxn];
int tot , head[maxn] , dis[maxn];
int root , maxp[maxn] , sum , sz[maxn] , ans1 , ans2 , maxx , temp[maxn];
bitset<maxn>vis;

bool operator < (const Node &x , const Node &y) {
	return x.len>y.len;
}

void add(int x , int y , int z) {
	tot++;
	e[tot].next = head[x];
	e[tot].to = y;
	e[tot].len = z;
	head[x] = tot;
}

void dij(int x) {
	int cnt = 0;
	vis.reset();
	Ms(dis,0x3f);
	dis[x]=0;
	priority_queue<Node>q;
	q.push(Node(0,x,0));
	while(cnt<n&&!q.empty()) {
		Node u=q.top();
		q.pop();
		if(vis[u.next]) continue;
		cnt++; vis[u.next]=1;
		add(u.to,u.next,u.len);
		add(u.next,u.to,u.len);
		for(int i=0; i<g[u.next].size(); i++) {
			int v=g[u.next][i].first;
			if(dis[v]>dis[u.next]+g[u.next][i].second) {
				dis[v] = dis[u.next]+g[u.next][i].second;
				q.push(Node(u.next,v,g[u.next][i].second));
			}
		}
	}
}

void getroot(int x , int f) {
	sz[x]=1; maxp[x]=0;
	Eo(i,x,e) {
		int v=e[i].to;
		if(f==v||vis[v]) continue;
		getroot(v,x);
		sz[x]+=sz[v];
		maxp[x]=max(maxp[x],sz[v]);
	}
	maxp[x]=max(maxp[x],sum-maxp[x]);
	if(maxp[x]<maxp[root]) root=x;
	return ;
}

void getlen(int x , int f , int c) {
	if(c==K) return ;
	Eo(i,x,e) {
		int v=e[i].to;
		if(v==f||vis[v]||!v) continue;
		temp[c]=max(temp[c],temp[c-1]+e[i].len);
		getlen(v,x,c+1);
	}
	return ;
}

void divide(int x) {
	Ms(dis,0);
	Ms(temp,0);
	Eo(i,x,e) {
		int v=e[i].to;
		if(vis[v]) continue;
		maxx=0;
		temp[1]=e[i].len;
		getlen(v,x,2);
		Fo(i,0,K) {
			for(int j=0; j<tmp[i].size(); j++) {
				
			}
		}
		/*Fo(j,1,K) {
			dis[j]=max(dis[j],temp[j]);	
			temp[j]=0;
		}*/
	}
	return ;
}

void sol(int x) {
	vis[x]=1;
	divide(x);
	Eo(i,x,e) {
		int v=e[i].to;
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
	cin>>T;
	while(T--) {
		cin>>n>>m>>K;
		Fo(i,1,m) {
			int x , y , z;
			cin>>x>>y>>z;
			g[x].push_back(make_pair(y,z));
			g[y].push_back(make_pair(x,z));
		}
		dij(1);
		//Fo(i,1,n) cout<<dis[i]<<" ";
		root=0; maxp[root]=sum=n;
		vis.reset();
		getroot(1,0);
		sol(root);
		//cout<<ans1<<" "<<ans2<<endl;
		Fo(i,1,n) {
			cout<<i<<":";
			Eo(j,i,e)
				cout<<" "<<e[j].to;
			cout<<endl;
		}
	}
	return 0;
}

