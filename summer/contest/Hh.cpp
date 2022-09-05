//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 1e5+5;
const LL maxm = 150000+5;
LL n, m, k;

LL tot, head[maxn], dis[maxn][10];

struct Edge {
	LL to, next, len;
}e[maxm<<1];

void add(LL x, LL y, LL z) {
	tot++;
	e[tot].next = head[x];
	e[tot].to = y;
	e[tot].len = z;
	head[x] =  tot;
}

struct Que {
	LL a, b, c;
};

bool operator < (const Que &a, const Que &b) {
	if(a.a!=b.a) return a.a<b.a;
	if(a.b!=b.b) return a.b<b.b;
	return a.c<b.c;
}

void dij(LL s) {
	priority_queue<Que> q;
	dis[s][0] = 0;
	q.push({0, s, 0});
	while(!q.empty()) {
		Que u = q.top(); q.pop();
		LL x=u.b, p=u.c, d=-u.a;
		if(d>dis[x][p]) continue;
		Eo(i,x,e) {
			LL v=e[i].to;
			if(dis[v][p]>dis[x][p]+e[i].len) {
				dis[v][p] = dis[x][p]+e[i].len;
				q.push({-dis[v][p], v, p});				
			}
			if(p<k&&dis[v][p+1]>dis[x][p]) {
				dis[v][p+1] = dis[x][p];
				q.push({-dis[v][p+1], v, p+1});
			}
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m>>k;
    Fo(i,1,m) {
    	LL x, y, z; cin>>x>>y>>z;
    	add(x, y, z);
    	add(y, x, z);
	}
	Ms(dis, 0x3f);
	dij(1);
	LL ans = INT_MAX;
	Fo(i,0,k) ans=min(ans, dis[n][i]);
	cout<<ans;
    return 0;
}
