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

const LL maxn = 205;
LL n, m;

struct Node {
    LL to, next, len;
    Node(){}
    Node(LL t, LL n, LL l) {
        to=t , next=n, len=l;
    }
}e[maxn<<1];

LL head[maxn], tot=1, a[maxn][maxn], dis[maxn], pre[maxn];

void add(LL x, LL y, LL z) {
    tot++;
    e[tot].next = head[x];
    e[tot].to = y;
    e[tot].len = z;
    head[x] = tot;
}

LL ans;

bool bfs() {
    bool vis[maxn]; Ms(vis,0);
    vis[1]=1;
    queue<LL>q;
    q.push(1);
    dis[1]=INF;
    while(!q.empty()) {
        LL u=q.front();
        if(u==n) return 1;
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
    LL x=n;
    while(x!=1) {
        LL p=pre[x];
        e[p].len-=dis[n];
        e[p^1].len+=dis[n];
        x=e[p^1].to;
    }
    ans+=dis[n];
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    while(cin>>m>>n) {
        ans=0; tot=1; Ms(a,0); Ms(e,0); Ms(head,0);
        Fo(i,1,m) {
            LL x, y, z;
            cin>>x>>y>>z;
            if(!a[x][y]) {
                add(x,y,z);
                add(y,x,0);
                a[x][y] = tot-1;
            } else e[a[x][y]].len+=z;
        }
        while(bfs()) {
            dfs();
        }
        cout<<ans<<endl;
    }
    return 0;
}