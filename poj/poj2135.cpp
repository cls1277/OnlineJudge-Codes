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

const LL maxn = 1e3+5;
const LL maxm = 1e4+5;
LL n, m, s, t;

struct Node {
    LL to, next, len, val;
    Node(){}
    Node(LL t, LL n, LL l, LL v) {
        to=t , next=n, len=l, val=v;
    }
}e[maxm<<2];

LL head[maxn], tot=1, dis[maxn], pre[maxn], val[maxn];

void add(LL x, LL y, LL z, LL w) {
    tot++;
    e[tot].next = head[x];
    e[tot].to = y;
    e[tot].len = z;
    e[tot].val = w;
    head[x] = tot;
}

LL mc, mf;

bool spfa() {
    bool flag=false;
    bool vis[maxn]; Ms(vis,0); Ms(val,0x7f); val[s]=0;
    vis[s]=1; dis[s]=INF;
    // Fo(i,1,n) val[i]=INF; val[s]=0;
    // pre[t]=-1;//!!!
    queue<LL>q;
    q.push(s);
    while(!q.empty()) {
        LL u=q.front();
        q.pop();
        if(u==t) flag=true;
        vis[u] = 0;
        Eo(i,u,e) {
            LL v=e[i].to;
            if(e[i].len>0&&val[v]>val[u]+e[i].val) {
                val[v] = val[u]+e[i].val;
                pre[v] = i;
                dis[v] = min(dis[u], e[i].len);
                if(!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return flag;
    // return pre[t]!=-1;
}

void dfs() {
    LL x=t;
    while(x!=s) {
        LL p=pre[x];
        e[p].len-=dis[t];
        e[p^1].len+=dis[t];
        x=e[p^1].to;
    }
    // mf += dis[t];
    mc += dis[t]*val[t];
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m;
    s=n+1; t=n+2;
    Fo(i,1,m) {
        LL x, y, w;
        cin>>x>>y>>w;
        add(x,y,1,w);
        add(y,x,0,-w);
        add(y,x,1,w);
        add(x,y,0,-w);
    }
    add(s,1,2,0);
    add(1,s,0,0);
    add(n,t,2,0);
    add(t,n,0,0);
    while(spfa()) {
        dfs();
    }
    cout<<mc<<endl;
    return 0;
}