//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 5e5+5;
LL n, m, tot, head[maxn*8], dis[maxn*8];
unordered_map<LL, LL> mp;
unordered_map<LL, bool> bad;

inline LL read() {
	LL x = 0, f = 1;char c = getchar();
	while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
	while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
	return x * f;
}

LL Hash(pair<LL, LL> x) {
    return x.first*1000000+x.second;
}

struct Seg {
    LL to, next, len;
}e[maxn*24];

pair<LL, LL> s, t;

void check(pair<LL, LL> x) {
    LL h = Hash(x);
    if(!mp[h]) {
        mp[h] = ++m;
        // mpp[m] = x;
    }
}

void add(LL x, LL y, LL z) {
    tot++;
    e[tot].next = head[x];
    e[tot].to = y;
    e[tot].len = z;
    head[x] = tot;
}

struct Que {
	LL len , num;
};

bool operator < (Que a , Que b) {
	return a.len > b.len;
}

void dij(LL _s) {
    for(int i=1; i<=m; i++) dis[i]=INT_MAX;
	dis[_s] = 0;
	priority_queue<Que>q;
	q.push({0, _s});
	while(!q.empty()) {
		Que u=q.top();
		q.pop();
		if(u.len!=dis[u.num]) continue;
		for(int i=head[u.num]; i;i=e[i].next) {
			LL v=e[i].to;
			if(dis[v]>dis[u.num]+e[i].len) {
				dis[v] = dis[u.num]+e[i].len;
				q.push({dis[v], v});
			}
		}
	}
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    n=read(); //cin>>n;
    Fo(i,1,n) {
        LL a[4];
        Fo(j,0,3) a[j]=read(); //cin>>a[j];
        Fo(j,0,3) {
            if(!a[j]) continue;
            pair<LL, LL> d = {i, a[j]}, k = {a[j], i};
            //back
            check(d); check(k);
            if(!bad[mp[Hash(d)]]||!bad[mp[Hash(k)]]) {
                bad[mp[Hash(d)]] = bad[mp[Hash(k)]] = 1;
                add(mp[Hash(d)], mp[Hash(k)], 1);
                add(mp[Hash(k)], mp[Hash(d)], 1);
            }
            //left
            if(!a[(j+1)%4]) continue;
            pair<LL, LL> b = {a[(j+1)%4], i}, c = {i, a[(j+1)%4]};
            check(b); check(c);
            add(mp[Hash(b)], mp[Hash(d)], 1);
            //right
            add(mp[Hash(k)], mp[Hash(c)], 0);
        }
        //front
        if(a[0]&&a[2]) {
            pair<LL, LL> x={a[0], i}, y={i, a[2]};
            pair<LL, LL> _x={a[2],i}, _y={i,a[0]};
            check(x); check(y); check(_x); check(_y);
            add(mp[Hash(x)], mp[Hash(y)], 1);
            add(mp[Hash(_x)], mp[Hash(_y)], 1);
        }
        if(a[1]&&a[3]) {
            pair<LL, LL> x={a[1], i}, y={i, a[3]};
            pair<LL, LL> _x={a[3],i}, _y={i,a[1]};
            check(x); check(y); check(_x); check(_y);
            add(mp[Hash(x)], mp[Hash(y)], 1);
            add(mp[Hash(_x)], mp[Hash(_y)], 1);
        }
    }
    s.first=read(); s.second=read(); t.first=read(); t.second=read();
    //cin>>s.first>>s.second>>t.first>>t.second;
    dij(mp[Hash(s)]);
    if(dis[mp[Hash(t)]]==INT_MAX) printf("-1");
    else printf("%lld",dis[mp[Hash(t)]]);
    return 0;
}