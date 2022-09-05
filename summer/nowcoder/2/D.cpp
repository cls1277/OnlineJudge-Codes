//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 1005;
const LL maxm = 2005;
const double eps = 1e-10;
LL n, m, head[maxn], tot, cnt[maxn];
double dis[maxn];
bool vis[maxn];

struct Edge {
    LL to, next; double len;
}e[maxm];

void add(LL x, LL y, double z) {
    tot++;
    e[tot].next = head[x];
    e[tot].to = y;
    e[tot].len = z;
    head[x] = tot;
}

bool judge(double w) {
	queue<LL>q;
    for(int i=1; i<=n; i++) {
        dis[i] = 0;
        cnt[i] = vis[i] = 0;
        q.push(i);
    }
	while(!q.empty()) {
		LL u = q.front();
		q.pop();
		vis[u] = 0;
		for(int i=head[u]; i; i=e[i].next) {
			LL v = e[i].to;
			if(dis[v]>dis[u]+e[i].len+w) {
				dis[v] = dis[u]+e[i].len+w;
				if(!vis[v]) {
					vis[v] = 1;
					q.push(v);
                    cnt[v] = cnt[u]+1;
                    if(cnt[v]>=n) return 1;
				}
			} 
		} 
	}
    return 0;
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m;
    Fo(i,1,m) {
        LL a, b, c, d; cin>>a>>b>>c>>d;
        add(b, d, -log(c*1.0/a));
    }
    double l=0, r=1;
    while(r-l>eps) {
        double mid = (l+r)/2;
        if(judge(-log(mid))) r = mid;
        else l = mid;
    }
//    cout<<l;
	printf("%.10lf",l);
    return 0;
}