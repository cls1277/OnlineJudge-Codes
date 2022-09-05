//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 2005;
const LL maxm = 3005;

struct Edge {
    LL to, next, len;
}e[maxm<<1];

LL n, m, tot, head[maxn], dis[maxn], cnt[maxn];
bool vis[maxn];

void add(LL x, LL y, LL z) {
    tot++;
    e[tot].next = head[x];
    e[tot].to = y;
    e[tot].len = z;
    head[x] = tot;
}

bool spfa(LL s) {
	for(int i=1; i<=n; i++) dis[i]=INT_MAX;
	queue<LL>q;
	dis[s] = 0;
	vis[s] = 1;
	q.push(s);
	while(!q.empty()) {
		LL u = q.front();
		q.pop();
		vis[u] = 0;
		for(int i=head[u]; i; i=e[i].next) {
			LL v = e[i].to;
			if(dis[v]>dis[u]+e[i].len) {
				dis[v] = dis[u]+e[i].len;
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        cin>>n>>m;
        tot = 0;
        Fo(i,1,n) {
            vis[i] = 0;
            dis[i] = head[i] = cnt[i] = 0;
        }
        Fo(i,1,m) {
            LL x, y, z; cin>>x>>y>>z;
            add(x, y, z);
            if(z>=0) add(y, x, z);
        }
        cout<<(spfa(1)?"YES":"NO")<<endl;
    }
    return 0;
}