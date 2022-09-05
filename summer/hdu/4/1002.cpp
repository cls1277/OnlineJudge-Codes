//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

inline LL read() {
	LL x = 0, f = 1;char c = getchar();
	while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
	while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
	return x * f;
}

const LL maxn = 1e5+5;
const LL maxm = 3e5+5;
LL n, m;

struct Edge {
    LL to, next, len;
}e[maxm];

LL head[maxn], tot;

void add(LL x, LL y, LL z) {
    tot++;
    e[tot] = {y, head[x], z};
    head[x] = tot;
}

LL Hash(LL x, LL y) {
    return x*1e5+y;
}

unordered_map<LL, LL> ed;

struct Que {
	LL len , num;
};

bool operator < (Que a , Que b) {
	return a.len > b.len;
}

LL dis[maxn];

unordered_map<LL, vector<LL>> node;

void dij(LL s) {
    for(int i=1; i<=n; i++) dis[i]=INT_MAX;
	dis[s] = 0;
	priority_queue<Que>q;
	q.push({0,s});
	while(!q.empty()) {
		Que u=q.top();
		q.pop();
		if(u.len!=dis[u.num]) continue;
		for(int i=head[u.num]; i;i=e[i].next) {
			LL v=e[i].to;
			if(dis[v]>dis[u.num]+e[i].len) {
				dis[v] = dis[u.num]+e[i].len;
				node[v].push_back(u.num);
				q.push({dis[v], v});
			} else if(dis[v]==dis[u.num]+e[i].len) {
                node[v].push_back(u.num);
            }
		}
	}
}

LL ans = 0;

void dfs(LL x, LL p) {
    if(x==1) {
        ans = max(ans, p);
        return ;
    }
    for(auto it:node[x]) {
        dfs(it, p+ed[Hash(it, x)]);
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; t=read(); //cin>>t;
    while(t--) {
        ans = tot= 0;
        node.clear();
        n=read(); m=read();
        vector<pair<LL, LL>> edd(m+1);
        Fo(i,1,m) {
            LL x, y, z, p; x=read(); y=read(); z=read(); p=read(); //cin>>x>>y>>z>>p;
            add(x, y, z);
            ed[Hash(x, y)] = p;
            edd[i] = {x, y};
        }
        dij(1);
        dfs(n, 0);
        printf("%lld %lld\n", dis[n], ans);
        Fo(i,1,m) ed[Hash(edd[i].first, edd[i].second)] = 0;
        Fo(i,1,n) {
            head[i] = 0;
            node[i].clear();
        }
    }
    return 0;
}
