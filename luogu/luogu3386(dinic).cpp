//By cls1277
#ifdef ONLINE_JUDGE
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#else
#include<bits/stdc++.h>
#endif
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
#define mk(_,__) make_pair(_,__)
#define pii pair<int,int>
#define ls x<<1
#define rs x<<1|1
#define endl '\n'
inline LL read() {
    LL x = 0, f = 1;char c = getchar();
    while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
    while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
    return x * f;
}

const LL maxn = 505;

struct Node {
    LL to, next, len;
}e[2*(50005+maxn*2)];

LL head[maxn<<1], tot, dis[maxn<<1], pre[maxn<<1], ans, s, t, E, a[maxn][maxn];

void add(LL x, LL y, LL z) {
    tot++;
    e[tot].next = head[x];
    e[tot].to = y;
    e[tot].len = z;
    head[x] = tot;
}

bool bfs() {
    bool vis[maxn<<1]; Ms(vis,0);
    vis[s]=1;
    queue<LL>q;
    q.push(s);
    dis[s]=INF;
    while(!q.empty()) {
        LL u=q.front();
        if(u==t) return 1;
        q.pop();
        Eo(i,u,e) {
            LL v=e[i].to;
            if(e[i].len<=0||vis[v]) continue;
            vis[v] = 1;
            q.push(v);
            pre[v] = i;
            dis[v] = min(dis[u] , e[i].len);
        }
    }
    return 0;
}

void dfs() {
    LL x=t;
    while(x!=s) {
        LL p=pre[x];
        e[p].len-=dis[t];
        e[p^1].len+=dis[t];
        x=e[p^1].to;
    }
    ans+=dis[t];
    return ;
}

LL n, m;

int main() {
    ios::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m>>E;
    s=n+m+1, t=n+m+2;
    tot = 1;
    Fo(i,1,E) {
        LL x,y; cin>>x>>y;
        if(!a[x][y]) {
            add(x, n+y, 1);
            add(n+y, x, 0);
            a[x][y] = tot-1;
        }
    }
    Fo(i,1,n) {
        add(s,i,1);
        add(i,s,0);
    }
    Fo(i,1,m) {
        add(n+i,t,1);
        add(t,n+i,0);
    }
    // Fo(i,1,n+m+2) {
    //     cout<<i<<":";
    //     Eo(j,i,e) {
    //         cout<<e[j].to<<" ";
    //     }
    //     cout<<endl;
    // }
    while(bfs()) {
        dfs();
    }
    cout<<ans;
    return 0;
}